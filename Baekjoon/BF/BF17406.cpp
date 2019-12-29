#include <iostream>
#include <vector>
#define INT_MAX 999999999
using namespace std;

//https://www.acmicpc.net/problem/17406 �迭������4
//BF

int map[51][51];
int turn[6][3];
bool checks[6]; //�̹� �������� �ƴ��� Ȯ��
int n, m, k,maxs = INT_MAX;

int getMinSum() {
	int max = INT_MAX, sums;
	for (int i = 0; i < n; i++) {
		sums = 0;
		for (int j = 0; j < m; j++) {
			sums += map[i][j];
		}
		max = max > sums ? sums : max;
	}
	return max;
}

void turnMap(int y, int x, int counts) {
	y -= 1; //������ �迭�� �ٸ��� ������ ����
	x -= 1;
	for (int j = 1; j <= counts; j++) {
		int temp = map[y - j][x - j]; //���� ���� �����´�.
		for (int i = y - j; i < y + j; i++) { //���� �̵�.
			map[i][x - j] = map[i + 1][x - j];
		}
		for (int i = x - j; i < x + j; i++) { //�Ʒ� �̵�.
			map[y + j][i] = map[y + j][i + 1];
		}
		for (int i = y + j; i > y - j; i--) { //������ �̵�.
			map[i][x + j] = map[i - 1][x + j];
		}
		for (int i = x + j; i > x - j; i--) { //���� �̵�.
			map[y - j][i] = map[y - j][i - 1];
		}
		map[y - j][x - j + 1] = temp; //�����Ѱ� ����
	}
}

void returnMap(int y, int x, int counts) {
	y -= 1; //������ �迭�� �ٸ��� ������ ����
	x -= 1;
	for (int j = 1; j <= counts; j++) {
		int temp = map[y - j][x - j]; //���� ���� �����´�.
		for (int i = x - j; i < x + j; i++) { //���� �̵�.
			map[y - j][i] = map[y - j][i + 1];
		}
		for (int i = y - j; i < y + j; i++) { //������ �̵�.
			map[i][x + j] = map[i + 1][x + j];
		}
		for (int i = x + j; i > x - j; i--) { //�Ʒ� �̵�.
			map[y + j][i] = map[y + j][i - 1];
		}
		for (int i = y + j; i > y - j; i--) { //���� �̵�.
			map[i][x - j] = map[i - 1][x - j];
		}
		map[y - j + 1][x - j] = temp; //�����Ѱ� ����
	}
}

void DFS(int counts) {
	if (counts == k) {
		int m_max = getMinSum();
		maxs = maxs > m_max ? m_max : maxs;
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!checks[i]) { //���� �ȵ��Ҵٸ�.
			checks[i] = true;
			turnMap(turn[i][0], turn[i][1], turn[i][2]);
			DFS(counts + 1);
			checks[i] = false;
			returnMap(turn[i][0], turn[i][1], turn[i][2]);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> turn[i][j];
		}
	}
	DFS(0);
	cout << maxs;
}