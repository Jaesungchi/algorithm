#include <iostream>
#include <queue>

//[지뢰찾기](https://www.acmicpc.net/problem/2140)

using namespace std;

char map[100][105];
int dx[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int n;

bool check(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (map[nx][ny] == '0') return 0;
	}

	return 1;
}

void doMinus(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (map[nx][ny] >= '0' && map[nx][ny] <= '9') 
			map[nx][ny]--;
	}
}

int main() {
	cin >> n;
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	int ret = (n - 2) * (n - 2);

	for (int i = 0; i < n; i++) 
		cin >> map[i];

	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (i == 1 || j == 1 || i == n - 2 || j == n - 2)
				if (check(i, j))
					doMinus(i, j);
				else
					ret--;
	cout << ret;
	return 0;
}
