#include <iostream>
using namespace std;

//[N-Queen](https://www.acmicpc.net/problem/9663)

int N,ans;
bool arr[16][16];

bool isCan(int i, int pos) {
	for(int x = 0; x < pos; x++)
		if (arr[i][x])
			return false;
	for (int x = pos - 1, y = i - 1; y >= 0; x--, y--)
		if (arr[y][x])
			return false;
	for (int x = pos - 1, y = i + 1; y < N; x--, y++)
		if (arr[y][x])
			return false;
	return true;
}

void DFS(int pos) {
	if (pos == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++)
		if (!arr[i][pos] && isCan(i, pos)) {
			arr[i][pos] = true;
			DFS(pos + 1);
			arr[i][pos] = false;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	DFS(0);
	cout << ans << "\n";
}