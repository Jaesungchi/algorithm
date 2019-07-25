#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/17144 미세먼지 안녕!
//시뮬레이션 , 미세먼지 확산이 중복해서 되는게 힘들었다.

int N, M, D, map[51][51], plusmap[51][51], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool UpGongGi = false;

void Gonggi(int y, int x, int mise, int direction, bool IsDown) {
	int m_dir = direction, temp;
	if (map[y][x] == -1) //돌아왔다면 종료
		return;
	if (y + dy[m_dir] < 0 || y + dy[m_dir] >= N || x + dx[m_dir] < 0 || x + dx[m_dir] >= M)
		if (IsDown) m_dir = (m_dir + 1) % 4; //아래바람
		else m_dir = (m_dir + 3) % 4; //윗바람
	temp = map[y][x]; //다음 바람에 보낼 미세먼지 저장
	map[y][x] = mise; //전바람에서 넘어온 미세먼지 등록
	Gonggi(y + dy[m_dir], x + dx[m_dir], temp, m_dir, IsDown);
}

void Mise(int y, int x) {
	int beforeData = map[y][x];
	int temp = beforeData / 5;
	for (int i = 0; i < 4; i++) { //자기것을 옆에 더해준다.
		if (y + dy[i] < 0 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >= M)
			continue; //구역을 넘어가면 패스
		if (map[y + dy[i]][x + dx[i]] == -1)
			continue; //공기청정기 자리 패스
		plusmap[y + dy[i]][x + dx[i]] += temp; //일단 더하기 맵에다가만 저장한다.
		beforeData -= temp; //값은 빼둔다.
	}
	map[y][x] = beforeData; //뺀 값을 원래 맵에 저장한다.
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