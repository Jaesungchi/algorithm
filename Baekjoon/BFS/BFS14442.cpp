#include <iostream>
#include <string>
#include <queue>
using namespace std;

//[벽 부수고 이동하기 2 난이도★★](https://www.acmicpc.net/problem/14442)

int N, M, K; // 세로 N 가로 M 벽 횟수 K
bool maps[1001][1001];
bool check[1001][1001][11]; //들렀나 안들렀나
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };

typedef struct car {
	int x, y; // 좌표
	int k; //부쉈는지 아닌지
	int counts; //횟수
}C;

//맵을 나갔는지 판단
bool isOut(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return true;
	return false;
}

int main() {
	string tmpS;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> tmpS;
		for (int j = 0; j < M; j++)
			if (tmpS[j] == '0')
				maps[i][j] = true;
			else
				maps[i][j] = false;
	}
	queue<C> q; //Q 저장용
	C start = { 0,0,0,1 }; //시작 위치 저장
	check[0][0][0] = true;
	q.push(start);
	while (!q.empty()) {
		C tmp = q.front(); //저장
		q.pop(); //삭제
		if (tmp.y == N - 1 && tmp.x == M - 1) {
			cout << tmp.counts << "\n";
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + dx[i];
			int ty = tmp.y + dy[i];
			if (isOut(tx, ty)) continue; //나갔으면 종료
			if (check[ty][tx][tmp.k]) continue; //이미 들린곳이면 종료
			if (maps[ty][tx]) { //벽이 아닌경우
				C tnew = { tx,ty,tmp.k,tmp.counts + 1 };
				check[ty][tx][tmp.k] = true;
				q.push(tnew);
			}
			else if (tmp.k < K) { //벽인경우
				C tnew = { tx,ty,tmp.k + 1,tmp.counts + 1 };
				check[ty][tx][tmp.k] = true;
				q.push(tnew);
			}
		}
	}
	cout << -1 << "\n"; //불가능한 경우
}