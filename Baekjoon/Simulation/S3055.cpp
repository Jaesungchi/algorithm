#include <iostream>
#include <queue>
using namespace std;

//[Ż�� ���̵� �ڡڡ�](https://www.acmicpc.net/problem/3055)

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

//���� Ȯ���Ű�� �Լ�.
void bigMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maps[i][j] == '*') {
				for (int z = 0; z < 4; z++) {
					int dx = j + mx[z], dy = i + my[z];
					if (isOutMap(dx,dy))
						continue; //���� ����� �ٸ�������.
					if (maps[dy][dx] != '.')
						continue; //Ȯ�� �� �� ���� ���̶�� �ٸ�������.
					maps[dy][dx] = 'n';
					visit[dy][dx] = true;
				}
				maps[i][j] = '+';// �̹� ����á����. ������ ����.
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
	int turn = -1; // ���� �ö� ���� ���� �о�����.
	S start = { sx,sy,0 };
	queue<S> q;
	q.push(start);
	visit[sy][sx] = true;
	while (!isGoal(q.front(), dx, dy)) { //�����Ҷ� ���� �ݺ�
		S tmp = q.front();
		q.pop();
		if (tmp.counts != turn) { //��ĭ �þ ������ �� Ȯ��.
			bigMap();
			turn++;
		}
		for (int i = 0; i < 4; i++) {
			int tx = tmp.x + mx[i], ty = tmp.y + my[i];
			if (isOutMap(tx, ty) || maps[ty][tx] == '*' || maps[ty][tx] == 'X' || visit[ty][tx])
				continue; //���� ����� �ٸ�������.
			S news = { tx,ty,tmp.counts + 1 };
			visit[ty][tx] = true;
			q.push(news);
		}
		if (q.empty()) //������ ���ٸ�.
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
			if (maps[i][j] == 'S') { //������ ����
				sy = i;
				sx = j;
				maps[i][j] = '.'; //.���� �ٲ۴�. �������� ���� �� ����.
			}
			if (maps[i][j] == 'D') { //������ ����
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