#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/3184 양

char map[251][251];
char tempData[251];
int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int allWolf= 0, allSheep =0;
int tempWolf, tempSheep;

void CheckGround(int y,int x) {
	if (map[y][x] == 'v') //임시저장 늑대 +1
		tempWolf++;
	else if (map[y][x] == 'o') //임시저장 양 +1
		tempSheep++;
	map[y][x] = '#'; //벽으로 다시 채운다.
	for (int i = 0; i < 4; i++) //현재 위치에서 4방향으로 다시 이동해본다.
		if (y + dy[i] >= 0 && y + dy[i] < R && x + dx[i] >= 0 && x + dx[i] < C) 
			if (map[y + dy[i]][x + dx[i]] != '#') //벽이 아니라면 이동한다.
				CheckGround(y + dy[i], x + dx[i]);
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> tempData;
		for (int j = 0; j < C; j++)
			map[i][j] = tempData[j]; //데이터를 맵으로 만들기 위해 이차원배열로 옮긴다.
	}
	for (int i = 0; i < R; i++) { //전체 맵을 돌아본다.
		for (int j = 0; j < C; j++) {
			tempWolf = tempSheep = 0; //한단계 사전저장을 초기화한다.
			if (map[i][j] == 'v' || map[i][j] == 'o') { //양이나 늑대면 들어간다.
				CheckGround(i, j);
				if (tempWolf >= tempSheep) //다 돌고 나온후 임시저장 늑대와 양을 비교해 All에 저장한다.
					allWolf += tempWolf;
				else if (tempWolf < tempSheep) 
					allSheep += tempSheep;
			}
		}
	}
	cout << allSheep << " " << allWolf;
}