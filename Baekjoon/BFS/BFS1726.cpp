#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NOR 1
#define SOU 3
#define WES 2
#define EAS 0
using namespace std;

//[로봇 난이도★★](https://www.acmicpc.net/problem/1726)

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }; //시계방향 + 1, 반시계 - 1
int ddir[2] = { 1, -1 };
int N, M; // 1 <= N,M <= 100
bool chk[101][101][4];
vector<vector<int>> arr;

typedef struct robot {
	int x, y;
	int dir, cnt;
	bool st; //직진중인지 확인
}R;

void inputMap() {
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> col;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			col.push_back(tmp);
		}
		arr.push_back(col);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	inputMap();

	R newR, desti;
	cin >> newR.y >> newR.x >> newR.dir;
	newR.y--, newR.x--, newR.st= false; //보정한다
	newR.cnt = 0;
	switch (newR.dir) {
	case 1:
		newR.dir = EAS;
		break;
	case 2:
		newR.dir = WES;
		break;
	case 3:
		newR.dir = SOU;
		break;
	case 4:
		newR.dir = NOR;
		break;
	}
	
	cin >> desti.y >> desti.x >> desti.dir;
	desti.y--, desti.x--; //보정한다.
	switch (desti.dir) {
	case 1:
		desti.dir = EAS;
		break;
	case 2:
		desti.dir = WES;
		break;
	case 3:
		desti.dir = SOU;
		break;
	case 4:
		desti.dir = NOR;
		break;
	}

	queue<R> q;
	q.push(newR);
	chk[newR.y][newR.x][newR.dir] = true;
	while (!q.empty()) {
		R tR = q.front();
		q.pop();

		if (tR.x == desti.x && tR.y == desti.y && tR.dir == desti.dir) {
			cout << tR.cnt;
			return 0;
		}
		//이동을 먼저 한다.
		tR.x += dx[tR.dir];
		tR.y += dy[tR.dir];
		if (tR.x >= 0 && tR.x < M && tR.y >= 0 && tR.y < N) {
			if (!chk[tR.y][tR.x][tR.dir] && arr[tR.y][tR.x] != 1) {
				R ttR = tR;
				if (!tR.st) {
					ttR.cnt++;
					ttR.st = true;
				}
				q.push(ttR);
				chk[ttR.y][ttR.x][ttR.dir] = true;
			}
		}
		tR.cnt++;
		tR.st = false;
		tR.x -= dx[tR.dir];
		tR.y -= dy[tR.dir];
		//회전을 한다.
		for (int i = 0; i < 2; i++) {
			R ttR = tR;
			ttR.dir += ddir[i];
			if (ttR.dir < 0)
				ttR.dir = 3;
			else
				ttR.dir %= 4;
			if (chk[ttR.y][ttR.x][ttR.dir])
				continue;
			q.push(ttR);
			chk[ttR.y][ttR.x][ttR.dir] = true;
		}
	}
}
