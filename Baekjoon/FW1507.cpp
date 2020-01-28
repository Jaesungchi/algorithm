#include <iostream>
#define CITY_MAX 21
using namespace std;

//[궁금한 민호 난이도★★★](https://www.acmicpc.net/problem/1507)
//Greedy를 적용하려다 플로이드와샬이 더 적당한거 같아 그걸로 적용.

int N; //도시
int map[CITY_MAX][CITY_MAX];
int outs[CITY_MAX][CITY_MAX];

bool Floyd() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!map[i][j]) continue; //다른 길이있음
			outs[i][j] = map[i][j];
			for (int k = 1; k <= N; k++) { // i - k + k - j
				if (!map[i][k] || !map[k][j]) continue;
				if (outs[i][j] == map[i][k] + map[k][j]) {
					outs[i][j] = 0;
					break;
				}
				if (outs[i][j] > map[i][k] + map[k][j]) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	if (Floyd()) {
		cout << -1 << "\n";
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			sum += outs[i][j];
	cout << sum << "\n";
}