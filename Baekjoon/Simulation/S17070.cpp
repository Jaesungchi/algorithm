#include <iostream>
#define MAX_SIZE 51
using namespace std;

//https://www.acmicpc.net/problem/17070 ������ �ű�� 1

int maps[MAX_SIZE][MAX_SIZE], N; //ó���� ���� (1,2) ������ 2 �̴�.
int dc[3] = { 1,1,0 }, dr[3] = { 0,1,1 },c_Size = 0;
bool CheckMap[MAX_SIZE][MAX_SIZE];

//�������� �� 3 ����
//�׿����� dc,dr ����

bool CheckGood(int r, int c) {
	for (int i = 0; i < 3; i++) { 
		int mr = r + dr[i];
		int mc = c + dc[i];
		if (mr <= 0 || mr > N || mc <= 0 || mc > N) //���� �Ѿ��.
			return false;
		if (CheckMap[mr][mc] || maps[mr][mc] == 1) //�̹� �������� �ְų� ���� ���
			return false;
	}
	return true;
}

void dfs(int r,int c,int dir) {
	if (r == N && c == N) { //�������� �����ϸ�
		c_Size++; //���� �߰��Ѵ�.
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 2)
			continue;
		if (dir == 2 && i == 0)
			continue;
		int mr = r + dr[i];
		int mc = c + dc[i];
		if (mr <= 0 || mr > N || mc <= 0 || mc > N) //���� �Ѿ��.
			continue;
		if (CheckMap[mr][mc] || maps[mr][mc] == 1) //�̹� �������� �ְų� ���� ���
			continue;
		if (i == 1) { //�밢���� ��� �׾� ���� �� Ȯ���ؾ���.
			if (!CheckGood(r, c))
				continue;
		}
		CheckMap[mr][mc] = true;
		dfs(mr, mc, i);
		CheckMap[mr][mc] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	CheckMap[1][1] = true;
	CheckMap[1][2] = true;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];

	dfs(1, 2, 0);

	cout << c_Size << "\n";
}