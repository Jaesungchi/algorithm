#include <iostream>
#include <queue>
using namespace std;

//[탈출 난이도 ★★★](https://www.acmicpc.net/problem/3055)

char maps[51][51];
bool visit[51][51];
int R, C;
int mx[4] = { 0,0,1,-1 }, my[4] = { -1,1,0,0 };

typedef struct s {
	int x, y;
	int counts;
}S;

bool isOutMap(int x, int y) {
	if (x < 0 || x >= C || y < 0 || y >= R)
		return true;
	return false;
}

bool isGoal(S dmember, int dx, int dy) {
	if (dmember.x == dx && dmember.y == dy)
		return true;
	return false;
}

//맵을 확장시키는 함수.
void bigMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maps[i][j] == '*') {
				for (int z = 0; z < 4; z++) {
					int dx = j + mx[z], dy = i + my[z];
					if (isOutMap(dx,dy))
						continue; //맵을 벗어나면 다른곳으로.
					if (maps[dy][dx] != '.')
						continue; //확장 할 수 없는 곳이라면 다른곳으로.
					maps[dy][dx] = 'n';
					visit[dy][dx] = true;
				}
				maps[i][j] = '+';// 이미 물이찼던곳. 갈일이 없다.
				visit[i][j] = true;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maps[i][j] == 'n')
				maps[i][j] = '*';
		}
	}
}

int BFS(int sx,int sy, int dx,int dy) {
	int turn = -1; // 턴이 올라갈 수록 맵이 넓어진다.
	S start = { sx,sy,0 };
	queue<S> q;
	q.push(start);
	visit[sy][sx] = true;
	while (!isGoal(q.front(), dx, dy)) { //도착할때 까지 반복
		S tmp = q.front();
		q.pop();
		if (tmp.counts != turn) { //한칸 늘어난 것으로 맵 확장.
			bigMap();
			turn++;
		}
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + mx[i], ty = tmp.y + my[i];
			if (isOutMap(tx, ty) || maps[ty][tx] == '*' || maps[ty][tx] == 'X' || visit[ty][tx])
				continue; //맵을 벗어나면 다른곳으로.
			S news = { tx,ty,tmp.counts + 1 };
			visit[ty][tx] = true;
			q.push(news);
		}
		if (q.empty()) //갈곳이 없다면.
			return 0;
	}
	return q.front().counts;
}

int main() {
	int sx, sy,dx,dy,result;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> maps[i];
		for (int j = 0; j < C; j++) {
			if (maps[i][j] == 'S') { //시작점 저장
				sy = i;
				sx = j;
				maps[i][j] = '.'; //.으로 바꾼다. 시작점은 먹힐 수 있음.
			}
			if (maps[i][j] == 'D') { //도착지 저장
				dy = i;
				dx = j;
			}
		}
	}
	result = BFS(sx, sy, dx, dy);
	if (result == 0)
		cout << "KAKTUS\n";
	else
		cout << result << "\n";
}