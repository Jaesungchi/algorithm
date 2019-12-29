#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/3190

int map[100][100] = { 0 };
int snakeX= 0, snakeY=0,snakeHead = 1,snakeLength = 1; //1은 오른쪽 2는 아래쪽 3은 왼쪽 0는 위쪽
int snakeLogX[100], snakeLogY[100];
int mapMax,second ;//맵의 최대값과 시간이 얼마나 지났는지 받기 위함. 
int moveb[100];
char movea[100];
bool Hit = false;


void CheckHit() {
	for (int i = 1; i < snakeLength; i++) {
		if (snakeX == snakeLogX[i] && snakeY == snakeLogY[i])
			Hit = true;
	}
}

void moveSnake() { //일단 몸이 늘어나고 사과가 있는경우 유지 사과가 없는경우 줄인다.  
	if (snakeHead == 1) { //오른쪽인경우
		snakeX += 1;
	}
	else if (snakeHead == 2) { //아래쪽인경우
		snakeY += 1;
	}
	else if (snakeHead == 3) { //왼쪽인경우
		snakeX -= 1;
	}
	else if (snakeHead == 0) { //위쪽인경우
		snakeY -= 1;
	}
	CheckHit(); //늘어난 몸이 자신의 신체랑 닿는지 확인
	if (map[snakeY][snakeX] == 1) { //만약 사과가 있다면 렝쓰를 늘린다.
		snakeLength += 1;
		map[snakeY][snakeX] = 0;
	}
	for (int i = snakeLength; i > 1; i--) {
		snakeLogX[i - 1] = snakeLogX[i - 2];
		snakeLogY[i - 1] = snakeLogY[i - 2];
	}
	snakeLogX[0] = snakeX;
	snakeLogY[0] = snakeY;
}

void TurnHead(char data) {
	if (data == 'D') {//오른쪽
		snakeHead = (snakeHead + 1) % 4; //오른쪽으로 회전
	}
	else { //왼쪽
		snakeHead = (snakeHead + 3) % 4; //왼쪽으로 회전
	}
}

int main() {
	int applex, appley, count,turn;
	cin >> mapMax;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> appley >> applex;
		map[appley-1][applex-1] = 1;
	}
	cin >> turn;
	for (int i = 0; i < turn; i++) {
		cin >> moveb[i] >> movea[i];
	}
	turn = 0;
	for (int i = 1; i < 10000; i++) { //10000의 행동.
		second = i;	
		moveSnake();
		if (snakeX < 0 || snakeY < 0 || snakeX >= mapMax || snakeY >= mapMax)
			break;
		if (Hit)
			break;	
		if (moveb[turn] == i) {
			TurnHead(movea[turn]);
			turn += 1;
		}	
	}
	cout << second;
}