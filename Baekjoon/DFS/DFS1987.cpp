#include <iostream>
using namespace std;

//[알파벳 난이도★★](https://www.acmicpc.net/problem/1987)

int R, C; //세로R 가로C
char maps[21][21]; //지도
bool alpha[27]; //알파벳을 들렀는지 아닌지 확인.
int maxs = 0; //최대 값
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }; //방향 벡터값

void DFS(int x, int y, int counts) {
	if (counts > maxs)
		maxs = counts;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		int alphaIndex = maps[ty][tx] - 'A'; //어떤 알파벳인지
		if (tx < 0 || tx >= C || ty < 0 || ty >= R)
			continue; //맵을 벗어난다면
		if (alpha[alphaIndex])
			continue; //들렀던 알파벳이라면
		alpha[alphaIndex] = true;
		DFS(tx, ty, counts + 1);
		alpha[alphaIndex] = false;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> maps[i];
	alpha[maps[0][0] - 'A'] = true; // 0,0 위치 알파벳은 들름
	DFS(0, 0, 1);
	cout << maxs << "\n";
}