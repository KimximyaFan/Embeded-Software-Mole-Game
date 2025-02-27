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

![image](https://github.com/user-attachments/assets/0c053ea1-c36e-44a5-80f0-f4b433fa1572)

<br><br><br>

### Q6 부저제어

<br>

![image](https://github.com/user-attachments/assets/696d5210-28b9-4b97-afcc-c602effb89c8)

<br>

![image](https://github.com/user-attachments/assets/5d886d5c-a4d4-4796-bbdb-e590d78f8430)

<br>

![image](https://github.com/user-attachments/assets/5ae0a638-5328-4796-9927-e3cbe9a76c64)

<br>

![image](https://github.com/user-attachments/assets/45a04582-eb4b-4485-9668-509bb9f66f53)

![image](https://github.com/user-attachments/assets/32144060-6622-4c1d-be5b-155678261d23)

<br>

![image](https://github.com/user-attachments/assets/b9d6bf93-3af2-4bc0-a498-130909e01865)

![image](https://github.com/user-attachments/assets/e1ea96c5-e5a7-4c5a-878c-711c25d3dde6)

![image](https://github.com/user-attachments/assets/71c6ce9b-2d6c-4bce-abd2-c82725dfd133)

![image](https://github.com/user-attachments/assets/3aa60669-868a-481a-b32b-0a65fe4bc899)

![image](https://github.com/user-attachments/assets/fb0e21c4-b37b-4617-8947-2e107f135bd1)

![image](https://github.com/user-attachments/assets/ab42cfd9-467c-41ef-ae58-af520c5e540e)


### M4 FND 제어

### M4 LED 제어

### M4 Button 모니터링

<br><br><br>

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

​## 영상

[![Video Label](http://img.youtube.com/vi/G65ISbxAG54/0.jpg)](https://youtu.be/G65ISbxAG54)

<br><br><br>
