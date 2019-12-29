#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/1063 ŷ
//�迭�� ������ �������� 0,0 �̾ƴ� ���� �Ʒ��� 0,0�̶�� ���� ��������

int stoneY, stoneX; //���� ��ǥ
int kingY, kingX; //���� ��ǥ
int moveCount; //ī����
char command[10]; //��ġ�� ���������� �迭
string commands; //��ɾ �ޱ����� string

void MoveKingAndStone(int y, int x) { //
	if (kingY + y < 0 || kingY + y >= 8 || kingX + x < 0 || kingX + x >= 8)
		return ;
	if (kingY + y == stoneY && kingX + x == stoneX) { //���� ��ġ�� �����ִٸ�
		if (stoneY + y < 0 || stoneY + y >= 8 || stoneX + x < 0 || stoneX + x >= 8)
			return;
		stoneY += y;
		stoneX += x;
	}
	kingY += y;
	kingX += x;
}

void incodingData() {
	if (commands == "R")
		MoveKingAndStone(0, 1);
	if (commands == "L")
		MoveKingAndStone(0, -1);
	if (commands == "B")
		MoveKingAndStone(-1, 0);
	if (commands == "T")
		MoveKingAndStone(1, 0);
	if (commands == "RT")
		MoveKingAndStone(1, 1);
	if (commands == "LT")
		MoveKingAndStone(1, -1);
	if (commands == "RB")
		MoveKingAndStone(-1, 1);
	if (commands == "LB")
		MoveKingAndStone(-1, -1);
}

void PrintData() {
	printf("%c%d\n", kingX + 'A', kingY + 1);
	printf("%c%d\n", stoneX + 'A', stoneY + 1);
}

int main() {
	for (int i = 0; i < 2; i++) {
		cin >> command;
		if (i == 0) {
			kingX = command[0] - 'A';
			kingY = command[1] - '0'-1; //���� 1�� 0�̶� 1����
		}
		else {
			stoneX = command[0] - 'A';
			stoneY = command[1] - '0'-1;
		}
	}
	cin >> moveCount;
	while (moveCount--) {
		cin >> commands;
		incodingData();
	}
	PrintData();
}