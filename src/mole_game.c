#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>

#define IOCTL_START_BUZZER      _IOW('b', 0x07, int)
#define IOCTL_END_BUZZER        _IOW('b', 0x09, int)
#define IOCTL_SET_TONE          _IOW('b', 0x0b, int)
#define IOCTL_SET_VOLUME        _IOW('b', 0x0c, int)
#define IOCTL_GET_TONE          _IOW('b', 0x0d, int)
#define IOCTL_GET_VOLUME        _IOW('b', 0x0e, int)

// 시리얼 장치 파일 디스크립터 변수 선언
static int serial_fd = -1;
static int buzzer_fd = -1;
struct termios tio;

int score = 0;

int button_index = -1;

int is_thread_end = 1;

double TONEHZ[8] = {523, 587, 659, 698, 783, 880, 987, 1046}; // 순서대로 도 레 미 파 솔 라 시 도

// 프로그램 오류 발생 시 디버깅 함수
int panic() {
    printf("[Panic] %i: %s\n", errno, strerror(errno));
    return 1;
}

double Random_Double(double a, double b) 
{
    return a + (b - a) * ((double)rand() / RAND_MAX);
}

int Random_Int(int a, int b) 
{
    return a + rand() % (b - a + 1);
}

void Sleep_Sec(double time)
{
    usleep( (int)(time * 1000000) );
}

// buzzer.c 복붙한 코드
void Play_Tone(int sound_index, int volume, double sound_time) 
{
    long tone = (long)((1.0f / TONEHZ[sound_index]) * 1000000000);

    buzzer_fd = open("/dev/buzzer", O_RDONLY);

	ioctl(buzzer_fd, IOCTL_SET_VOLUME, volume);
 	ioctl(buzzer_fd, IOCTL_SET_TONE, tone);
	
	ioctl(buzzer_fd, IOCTL_START_BUZZER, 0);

	Sleep_Sec(sound_time);

	ioctl(buzzer_fd, IOCTL_END_BUZZER, 0);

	close(buzzer_fd);
}

// 게임 시작 사운드
void Game_Start_Sound() 
{
    int music[5] = { 0, 1, 2, 1 ,0 };

    for (int i=0; i<5; i++)
        Play_Tone(i, 15000, 0.1);
}

// 게임 종료 사운드
void Game_End_Sound() 
{
    int music[8] = { 4, 0, 1, 2 ,3, 4, 0, 0 };

    for (int i=0; i<8; i++)
        Play_Tone(i, 15000, 0.1);
}

void Mole_Hit_Sound()
{
    Play_Tone(7, 15000, 0.1);
}

void Mole_Appear_Sound()
{
    Play_Tone(5, 15000, 0.1);
}

void Led_Off(int index)
{
    unsigned char msg2[] = { 0x12, 0x21, 0x30 + index, 0x31 - atoi("0"), 0x13 };

    write(serial_fd, msg2, sizeof(msg2));
}

void Led_On(int index)
{
    unsigned char msg1[] = { 0x12, 0x21, 0x30 + index, 0x31 - atoi("1"), 0x13 };

    write(serial_fd, msg1, sizeof(msg1));
}

void Score_Update()
{
    int a;
    int b;
    int c;

    score += 25;

    a = score / 100;
    b = (score % 100) / 10;
    c = score % 10;

	unsigned char msg1[] = { 0x12, 0x23, 0x30 + 0, 0x30 + a, 0x13 };
    unsigned char msg2[] = { 0x12, 0x23, 0x30 + 1, 0x30 + b, 0x13 };
    unsigned char msg3[] = { 0x12, 0x23, 0x30 + 2, 0x30 + c, 0x13 };

	write(serial_fd, msg1, sizeof(msg1));
    write(serial_fd, msg2, sizeof(msg2));
    write(serial_fd, msg3, sizeof(msg3));
}

void *Get_Button(void *arg)
{
    is_thread_end = 0;

    char read_buf[5];

    memset(&read_buf, '\0', sizeof(read_buf));

    button_index = -1;

    int num_bytes = read(serial_fd, &read_buf, sizeof(read_buf));

    button_index = read_buf[2] - 0x30;

    is_thread_end = 1;
}

void Mole_Hit()
{
    Mole_Hit_Sound();
    Score_Update();
}

void Mole_Game()
{
    int mole_appear_count = 20;
    int count = 0;
    int mole_index = 0;
    double timer_tic = 0.02;
    double mole_maintain_time = 0;
    double next_mole_appear_time = 0;
    double elapsed_time = 0;

    pthread_t tid; // 쓰레드 식별자

    while (1)
    {
        if ( count > mole_appear_count )
            break;
        
        elapsed_time = 0;
        mole_index = Random_Int(0, 4);
        mole_maintain_time = Random_Double(0.15, 0.4);
        next_mole_appear_time = Random_Double(0.4, 1.0);

        Led_On(mole_index);
        Mole_Appear_Sound();

        if ( is_thread_end == 1 )
        {
            pthread_create(&tid, NULL, Get_Button, NULL);
        }

        while (1)
        {
            Sleep_Sec(timer_tic);
            elapsed_time += timer_tic;

            if ( button_index == mole_index )
            {
                Mole_Hit();
                break;
            }
            else if ( elapsed_time >= mole_maintain_time )
                break;
        }
        button_index = -1;
        Led_Off(mole_index);

        Sleep_Sec(next_mole_appear_time);

        count += 1;
    }
}

void Initialize()
{
    // 시리얼 장치 열기
    serial_fd = open("/dev/ttymxc1", O_RDWR);

    if (serial_fd == -1) return panic();

    // termios 구조체 초기화
    bzero(&tio, sizeof(tio));
    
    // 통신 속도 115200, RTS/CTS 활성화, 8비트, 모뎀 제어 라인 무시
    tio.c_cflag = B115200 | CRTSCTS | CS8 | CLOCAL;
    // 프레임, 페리티 에러 무시
    tio.c_iflag = IGNPAR;
    tio.c_oflag = 0;
    tio.c_lflag = 0;
    // 타임 아웃 설정 (데이터가 수신될 때 까지 대기)
    tio.c_cc[VTIME] = 0;
    // 최소 읽기 바이트 수
    tio.c_cc[VMIN] = 5;

    // 시리얼 통신 설정
    if (tcsetattr(serial_fd, TCSANOW, &tio) != 0) return panic();

    for (int i=0; i<=4; i++)
        Led_Off(i);

    unsigned char msg1[] = { 0x12, 0x23, 0x30 + 0, 0x30 + 0, 0x13 };
    unsigned char msg2[] = { 0x12, 0x23, 0x30 + 1, 0x30 + 0, 0x13 };
    unsigned char msg3[] = { 0x12, 0x23, 0x30 + 2, 0x30 + 0, 0x13 };

    write(serial_fd, msg1, sizeof(msg1));
    write(serial_fd, msg2, sizeof(msg2));
    write(serial_fd, msg3, sizeof(msg3));
}

void End()
{
    close(serial_fd);
}

int main(void) {
    Initialize();

	Game_Start_Sound();

    printf("Mole Game Start! \n");

    Sleep_Sec(1.0);

    Mole_Game();

    Game_End_Sound();

    End();

    printf("Mole Game End! \n\n");

	return 0;
}