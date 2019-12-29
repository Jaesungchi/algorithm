#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/3184 ��

char map[251][251];
char tempData[251];
int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int allWolf= 0, allSheep =0;
int tempWolf, tempSheep;

void CheckGround(int y,int x) {
	if (map[y][x] == 'v') //�ӽ����� ���� +1
		tempWolf++;
	else if (map[y][x] == 'o') //�ӽ����� �� +1
		tempSheep++;
	map[y][x] = '#'; //������ �ٽ� ä���.
	for (int i = 0; i < 4; i++) //���� ��ġ���� 4�������� �ٽ� �̵��غ���.
		if (y + dy[i] >= 0 && y + dy[i] < R && x + dx[i] >= 0 && x + dx[i] < C) 
			if (map[y + dy[i]][x + dx[i]] != '#') //���� �ƴ϶�� �̵��Ѵ�.
				CheckGround(y + dy[i], x + dx[i]);
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> tempData;
		for (int j = 0; j < C; j++)
			map[i][j] = tempData[j]; //�����͸� ������ ����� ���� �������迭�� �ű��.
	}
	for (int i = 0; i < R; i++) { //��ü ���� ���ƺ���.
		for (int j = 0; j < C; j++) {
			tempWolf = tempSheep = 0; //�Ѵܰ� ���������� �ʱ�ȭ�Ѵ�.
			if (map[i][j] == 'v' || map[i][j] == 'o') { //���̳� ����� ����.
				CheckGround(i, j);
				if (tempWolf >= tempSheep) //�� ���� ������ �ӽ����� ����� ���� ���� All�� �����Ѵ�.
					allWolf += tempWolf;
				else if (tempWolf < tempSheep) 
					allSheep += tempSheep;
			}
		}
	}
	cout << allSheep << " " << allWolf;
}