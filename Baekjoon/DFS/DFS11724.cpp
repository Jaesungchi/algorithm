#include <iostream>
using namespace std;
//[연결 요소의 개수 난이도★](https://www.acmicpc.net/problem/11724)

bool tree[1001][1001];
bool isGo[1001];
int N, M, counts = 0;

void DFS(int num) {
	isGo[num] = true;
	for (int i = 1; i <= N; i++) {
		if (isGo[i]) continue; //들렀던 곳은 안감
		if (tree[num][i])
			DFS(i);
	}
}

int main() {
	int tmp1, tmp2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		tree[tmp1][tmp2] = true;
		tree[tmp2][tmp1] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (isGo[i]) continue;
		counts += 1;
		DFS(i);
	}
	cout << counts;
}