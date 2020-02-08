#include <iostream>
#include <queue>
using namespace std;

//[말이 되고픈 원숭이 난이도★★](https://www.acmicpc.net/problem/1600)

int K, W, H;
bool map[201][201];
int check[201][201][31];
int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
int my[8] = { -1,-2,-2,-1,1,2,2,1 }, mx[8] = { -2,-1,1,2,2,1,-1,-2 };

typedef struct start {
	int x, y;
	int k;
	int move;
}S;

int main() {
	int tmp;
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> tmp;
			if (tmp == 0)
				map[i][j] = true;
		}
	queue<S> q;
	q.push({ 0,0,0,0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		S tmp = q.front();
		q.pop();
		if (tmp.x == W - 1 && tmp.y == H - 1) {
			cout << tmp.move << "\n";
			return 0 ;
		}
		if (tmp.k < K) { //말로 이동
			for (int i = 0; i < 8; i++) {
				int tx = tmp.x + mx[i];
				int ty = tmp.y + my[i];
				if (tx < 0 || ty < 0 || tx >= W || ty >= H) continue;
				if (!map[ty][tx] || check[ty][tx][tmp.k + 1]) continue; //들렀던 곳
				check[ty][tx][tmp.k + 1] = true;
				q.push({tx,ty,tmp.k+1,tmp.move+1});
			}
		}
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + dx[i];
			int ty = tmp.y + dy[i];
			if (tx < 0 || ty < 0 || tx >= W || ty >= H) continue;
			if (!map[ty][tx] || check[ty][tx][tmp.k]) continue; //들렀던 곳
			check[ty][tx][tmp.k] = true;
			q.push({ tx,ty,tmp.k,tmp.move + 1 });
		}
	}
	cout << -1 << "\n";
}