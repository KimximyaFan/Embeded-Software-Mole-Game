# Embeded-Software-Mole-Game

<br><br>

## 작업시점
2024/06

<br><br><br>

## 하드웨어

<br>

### H-EMbed-TKU 보드의 Q6 모듈과 M4 모듈

![image](https://github.com/user-attachments/assets/1c5ed467-47ac-4b25-b6e9-9dc3f5de7ea7)

![image](https://github.com/user-attachments/assets/92305bf2-7bdc-43a1-a3aa-6d2cba3ed022)

![image](https://github.com/user-attachments/assets/5407b351-5cf2-463a-991c-1979e6f19be7)


<br><br><br>

## 선작업

<br><br><br>

## 활용한 기능
<br>

![image](https://github.com/user-attachments/assets/eb26084e-fd25-408e-b1ae-8d54b5b199d1)


<br>

![image](https://github.com/user-attachments/assets/0c053ea1-c36e-44a5-80f0-f4b433fa1572)

<br><br><br>

### Q6 부저제어

<br>

![image](https://github.com/user-attachments/assets/1af5f4ed-7691-46f0-8b8e-f66fa5708928)

<br>

![image](https://github.com/user-attachments/assets/5ae0a638-5328-4796-9927-e3cbe9a76c64)

<br>


![image](https://github.com/user-attachments/assets/45a04582-eb4b-4485-9668-509bb9f66f53)

![image](https://github.com/user-attachments/assets/32144060-6622-4c1d-be5b-155678261d23)

<br>

![image](https://github.com/user-attachments/assets/b9d6bf93-3af2-4bc0-a498-130909e01865)

![image](https://github.com/user-attachments/assets/e1ea96c5-e5a7-4c5a-878c-711c25d3dde6)

![image](https://github.com/user-attachments/assets/71c6ce9b-2d6c-4bce-abd2-c82725dfd133)

![image](https://github.com/user-attachments/assets/29e4eeb9-68f1-4374-9e97-279bacde7a94)

위 그림과 같이 구현 <br><br>

![image](https://github.com/user-attachments/assets/3aa60669-868a-481a-b32b-0a65fe4bc899)

<br>

![image](https://github.com/user-attachments/assets/fb0e21c4-b37b-4617-8947-2e107f135bd1)

<br>

![image](https://github.com/user-attachments/assets/04d36cc1-1837-4ef0-a07b-49a6efe9bd61)

![image](https://github.com/user-attachments/assets/0c0c6f94-f525-4b31-bb23-f2f87ffe6f5f)

![image](https://github.com/user-attachments/assets/ab42cfd9-467c-41ef-ae58-af520c5e540e)

소리 관련 최종 구현
<br>
<br>
<br>
<br>

### M4 FND 제어

<br>

![image](https://github.com/user-attachments/assets/c5d7c25d-86d8-45b1-b13b-4f83f1611f99)

<br>

![image](https://github.com/user-attachments/assets/ce59a6b6-98b2-461d-947d-f60f2b00a302)

<br>
<br>

![image](https://github.com/user-attachments/assets/1f6497d9-16df-487e-80eb-92f688113c6c)

<br>

구현은 위 그림과 같다 <br>
msg1 : fnd의 세번 째 자릿 수 조작 <br>
msg2 : fnd의 두번 째 자릿 수 조작 <br>
msg3 : fnd의 첫번 째 자릿 수 조작 <br>
<br>
그 후, serial_fd 에 write해서 Q6에서 M4로 통신 후 <br>
갱신된 점수 값을 디스플레이 한다 <br>

<br>
<br>
<br>
<br>

### M4 LED 제어

<br>

![image](https://github.com/user-attachments/assets/a8ac2875-a884-4344-9a6f-2bd1d35ac7dd)

<br>

![image](https://github.com/user-attachments/assets/b5382bf8-c59b-4f78-820a-8b0019042b8f)

<br>
<br>

![image](https://github.com/user-attachments/assets/44e77780-1e35-4eeb-8c0c-6a7678182114)

<br>

구현은 위 그림과 같다 <br>

led를 키려면 3번째 인자에 atoi 값을 1로 <br>
led를 끄려면 0으로 하는게 특징이고, <br>
직관적으로 사용하기 위해서, led on, led off 로 함수를 나눴다 <br>
led는 총 5개 있으므로 0~4 인덱스 값을 받아서 on off 할 수 있게 함수를 만들었다 <br>

<br>
<br>
<br>
<br>

### M4 Button 모니터링

<br>

![image](https://github.com/user-attachments/assets/b4ae540f-3473-49c5-a1b3-fe40cc9b7e9b)

<br>

![image](https://github.com/user-attachments/assets/dc833aa0-6e67-49a3-927d-33bfc69b61d2)

<br>

![image](https://github.com/user-attachments/assets/236acea3-66c5-40eb-b03c-a9fa4507fbf7)

구현은 위 그림과 같다 <br>

![image](https://github.com/user-attachments/assets/d6f7c9fe-9168-4405-997d-925433823e09)

![image](https://github.com/user-attachments/assets/4e4e315c-4cd0-440f-a265-60842a887498)

buf의 2번 인덱스값은 VAR1를 나타낸다 <br>
해당 값을 읽어와서 0x30을 빼면 인덱스를 알 수 있다 <br>
그리고 read 부분은 프로그램이 진행되지 않고 걸려있는 형태기 때문에, 쓰레딩으로 구현할 필요가 있다 <br>

<br>

![image](https://github.com/user-attachments/assets/554a12fb-a86b-42d3-8697-0cc6978dc837)

pthread로 button 모니터링을 하며, <br>
is_thread_end와 button_index 값이 갱신되는 걸로 정보를 판별 할 수 있다 <br>

<br><br><br><br>

## 프로그램 플로우차트

![image](https://github.com/user-attachments/assets/1212337d-3828-438c-a15c-9ee62f1d0514)

<br><br><br>

## 프로그램 원리

![image](https://github.com/user-attachments/assets/3a356275-6cc6-44ad-9c06-9abd4af40a57)

프로그램의 전체적인 흐름은 위 그림과 같다

<br><br><br>

![image](https://github.com/user-attachments/assets/42313325-d3a8-4bf3-a9a5-7de45a4656a5)

Initialize() <br>
: 프로그램 시작 시, 각종 변수들을 초기화 한다​ <br>

Game_Start_Sound() <br>
: 게임 시작을 알리는 부저를 울린다​ <br>

Mole_Game() <br>
: 두더지 게임을 시작한다​ <br>

<br><br><br>

![image](https://github.com/user-attachments/assets/5a7308d4-a5f7-4050-8ca0-9cb76a5add32)

Led_On() <br>
: LED 점멸이 두더지 역할을 한다​ <br>

​Mole_Appear_Sound() <br>
: LED 점멸시 두더지가 나왔음을 알리는 부저도 함께 울린다​ <br>

​*Get_Button() <br>
: 버튼을 누르는게 두더지를 잡는 역할, 버튼 모니터링을 한다​ <br>

<br><br><br>

![image](https://github.com/user-attachments/assets/5bfd0807-4d76-471c-b901-3657573d16ed)

Mole_Hit() <br>
Mole_Hit_Sound() <br>
Score_Update() <br>
: 사용자가 정해진 시간 내에 맞는 위치의 버튼을 누르면, <br> 
두더지를 잡았음을 알리는 부저가 울리고, FND를 통해 점수 값이 갱신된다​ <br> 

Led_Off() <br>​
: 해당 위치의 LED는 꺼진다 <br>

<br><br><br>

![image](https://github.com/user-attachments/assets/d3b86ee5-d40e-45ab-bf4d-c26722e78be5)
​

두더지 등장 횟수 20회를 충족하면 루프가 끝나게 되며, <br>
게임 종료를 알리는 부저가 울리고, 후처리를 한 후 프로그램이 종료된다. <br>

## 영상

[![Video Label](http://img.youtube.com/vi/G65ISbxAG54/0.jpg)](https://youtu.be/G65ISbxAG54) <br>
(클릭시 유튜브 영상으로 이동)
<br><br><br>
