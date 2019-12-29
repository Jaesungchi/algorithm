#include <iostream>
#define MAP_MAX 17
using namespace std;

//https://www.acmicpc.net/problem/17135 ĳ�� ���潺
//�������� �޼ҵ� �����鼭 �ذ�

int N, M, D ,maps[MAP_MAX][MAP_MAX],tmaps[MAP_MAX][MAP_MAX],m_kill = 0;

void Prints() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M; j++)
			cout << tmaps[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void CopyMap() {
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < M; j++)
			tmaps[i][j] = maps[i][j];
}

bool CheckEnemy() {
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < M; j++)
			if (tmaps[i][j] == 1)
				return true;
	return false;
}

void MoveEnemy() {
	for(int i = N-1 ; i >= 0 ; i--) //�Ʒ��� �ִ°� ���� �ű��.
		for(int j = 0 ; j < M ; j++)
			if (tmaps[i][j] == 1) { 
				if (i + 1 < N) //�ʾȿ� �ִٸ�
					tmaps[i + 1][j] = 1; //��ĭ �Ʒ���
				tmaps[i][j] = 0; //���� �ڸ��� �����.
			}
}
void ShotEnemy(int R) {
	int a, b;
	for (int ranges = 1; ranges <= D; ranges++) //�Ÿ���ŭ ���. �Ÿ��� 1����
		for (int j = 0; j < M; j++) //������ �����ͺ��� ����.
			for (int i = N - 1; i >= 0; i--) {
				if (tmaps[i][j] >= 1) { //���ΰ��
					a = j - R > 0 ? j - R : R - j; //���� ��ġ�� ���Ѵ�.
					b = N - i > 0 ? N - i : i - N;
					if (a + b == ranges) { //�Ÿ���ŭ�̸� ���.
						tmaps[i][j] += 1; //����� +1 
						return; //Ż���Ѵ�.
					}
				}
			}
}

int Jungri() {
	int kills = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tmaps[i][j] > 1) {
				tmaps[i][j] = 0;
				kills++;
			}
	return kills;
}

//1. �ü��� ȭ���� ���. (���� ���� �� �� �� ����)
//2. ���� ��ĭ �̵��Ѵ�.
void Start() {
	int kills = 0;
	while (CheckEnemy()) { //���� �ִٸ� ��� ��ȯ.
		for (int j = 0; j < M; j++) {// �� ���� �ü����� ���.
			if (tmaps[N][j] == 0) //�ü��� �ƴϸ� �ѱ��.
				continue;
			ShotEnemy(j);
		}
		kills += Jungri();
		MoveEnemy();
	}
	m_kill = m_kill > kills ? m_kill : kills; // �ִ밪�� �ٲ��ش�.
}

void SetArrow(int count,int mX) {
	if (count == 3) {
		CopyMap();
		Start();
		return;
	}
	if (mX == M)
		return;
	maps[N][mX] = 9; //9�� �ü�
	SetArrow(count + 1, mX + 1);
	maps[N][mX] = 0;
	SetArrow(count, mX + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maps[i][j];

	SetArrow(0,0);
	cout << m_kill << "\n";
}