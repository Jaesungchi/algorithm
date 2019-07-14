#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/3190

int map[100][100] = { 0 };
int snakeX= 0, snakeY=0,snakeHead = 1,snakeLength = 1; //1�� ������ 2�� �Ʒ��� 3�� ���� 0�� ����
int snakeLogX[100], snakeLogY[100];
int mapMax,second ;//���� �ִ밪�� �ð��� �󸶳� �������� �ޱ� ����. 
int moveb[100];
char movea[100];
bool Hit = false;


void CheckHit() {
	for (int i = 1; i < snakeLength; i++) {
		if (snakeX == snakeLogX[i] && snakeY == snakeLogY[i])
			Hit = true;
	}
}

void moveSnake() { //�ϴ� ���� �þ�� ����� �ִ°�� ���� ����� ���°�� ���δ�.  
	if (snakeHead == 1) { //�������ΰ��
		snakeX += 1;
	}
	else if (snakeHead == 2) { //�Ʒ����ΰ��
		snakeY += 1;
	}
	else if (snakeHead == 3) { //�����ΰ��
		snakeX -= 1;
	}
	else if (snakeHead == 0) { //�����ΰ��
		snakeY -= 1;
	}
	CheckHit(); //�þ ���� �ڽ��� ��ü�� ����� Ȯ��
	if (map[snakeY][snakeX] == 1) { //���� ����� �ִٸ� ������ �ø���.
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
	if (data == 'D') {//������
		snakeHead = (snakeHead + 1) % 4; //���������� ȸ��
	}
	else { //����
		snakeHead = (snakeHead + 3) % 4; //�������� ȸ��
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
	for (int i = 1; i < 10000; i++) { //10000�� �ൿ.
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