#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/17144 �̼����� �ȳ�!
//�ùķ��̼� , �̼����� Ȯ���� �ߺ��ؼ� �Ǵ°� �������.

int N, M, D, map[51][51], plusmap[51][51], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool UpGongGi = false;

void Gonggi(int y, int x, int mise, int direction, bool IsDown) {
	int m_dir = direction, temp;
	if (map[y][x] == -1) //���ƿԴٸ� ����
		return;
	if (y + dy[m_dir] < 0 || y + dy[m_dir] >= N || x + dx[m_dir] < 0 || x + dx[m_dir] >= M)
		if (IsDown) m_dir = (m_dir + 1) % 4; //�Ʒ��ٶ�
		else m_dir = (m_dir + 3) % 4; //���ٶ�
	temp = map[y][x]; //���� �ٶ��� ���� �̼����� ����
	map[y][x] = mise; //���ٶ����� �Ѿ�� �̼����� ���
	Gonggi(y + dy[m_dir], x + dx[m_dir], temp, m_dir, IsDown);
}

void Mise(int y, int x) {
	int beforeData = map[y][x];
	int temp = beforeData / 5;
	for (int i = 0; i < 4; i++) { //�ڱ���� ���� �����ش�.
		if (y + dy[i] < 0 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >= M)
			continue; //������ �Ѿ�� �н�
		if (map[y + dy[i]][x + dx[i]] == -1)
			continue; //����û���� �ڸ� �н�
		plusmap[y + dy[i]][x + dx[i]] += temp; //�ϴ� ���ϱ� �ʿ��ٰ��� �����Ѵ�.
		beforeData -= temp; //���� ���д�.
	}
	map[y][x] = beforeData; //�� ���� ���� �ʿ� �����Ѵ�.
}

void DoPlus() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			map[i][j] += plusmap[i][j];
			plusmap[i][j] = 0;
		}
}

int CountSum() {
	int sums = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] > 0)
				sums += map[i][j];
	return sums;
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	for (int k = 0; k < D; k++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] > 0)
					Mise(i, j);
		DoPlus();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == -1 && !UpGongGi) {
					Gonggi(i, j + 1, 0, 0, UpGongGi);
					UpGongGi = true;
				}
				else if (map[i][j] == -1) {
					Gonggi(i, j + 1, 0, 0, UpGongGi);
					UpGongGi = false;
				}
	}
	cout << CountSum() << "\n";
}