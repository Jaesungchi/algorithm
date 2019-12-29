#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/1063 킹
//배열의 순서가 왼쪽위가 0,0 이아닌 왼쪽 아래가 0,0이라는 점을 유의하자

int stoneY, stoneX; //돌의 좌표
int kingY, kingX; //왕의 좌표
int moveCount; //카운터
char command[10]; //위치를 나누기위한 배열
string commands; //명령어를 받기위한 string

void MoveKingAndStone(int y, int x) { //
	if (kingY + y < 0 || kingY + y >= 8 || kingX + x < 0 || kingX + x >= 8)
		return ;
	if (kingY + y == stoneY && kingX + x == stoneX) { //같은 위치에 돌이있다면
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
			kingY = command[1] - '0'-1; //문자 1은 0이랑 1차이
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