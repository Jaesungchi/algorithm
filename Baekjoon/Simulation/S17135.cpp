#include <iostream>
#define MAP_MAX 17
using namespace std;

//https://www.acmicpc.net/problem/17135 캐슬 디펜스
//차근차근 메소드 만들어가면서 해결

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
	for(int i = N-1 ; i >= 0 ; i--) //아래에 있는것 부터 옮긴다.
		for(int j = 0 ; j < M ; j++)
			if (tmaps[i][j] == 1) { 
				if (i + 1 < N) //맵안에 있다면
					tmaps[i + 1][j] = 1; //한칸 아래로
				tmaps[i][j] = 0; //원래 자리는 지운다.
			}
}
void ShotEnemy(int R) {
	int a, b;
	for (int ranges = 1; ranges <= D; ranges++) //거리만큼 쏜다. 거리는 1부터
		for (int j = 0; j < M; j++) //성에서 가까운것부터 돈다.
			for (int i = N - 1; i >= 0; i--) {
				if (tmaps[i][j] >= 1) { //적인경우
					a = j - R > 0 ? j - R : R - j; //현재 위치랑 비교한다.
					b = N - i > 0 ? N - i : i - N;
					if (a + b == ranges) { //거리만큼이면 쏜다.
						tmaps[i][j] += 1; //쏜것은 +1 
						return; //탈출한다.
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

//1. 궁수가 화살을 쏜다. (같은 적을 쏠 수 도 잇음)
//2. 적이 한칸 이동한다.
void Start() {
	int kills = 0;
	while (CheckEnemy()) { //적이 있다면 계속 순환.
		for (int j = 0; j < M; j++) {// 맨 왼쪽 궁수부터 쏜다.
			if (tmaps[N][j] == 0) //궁수가 아니면 넘긴다.
				continue;
			ShotEnemy(j);
		}
		kills += Jungri();
		MoveEnemy();
	}
	m_kill = m_kill > kills ? m_kill : kills; // 최대값을 바꿔준다.
}

void SetArrow(int count,int mX) {
	if (count == 3) {
		CopyMap();
		Start();
		return;
	}
	if (mX == M)
		return;
	maps[N][mX] = 9; //9가 궁수
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