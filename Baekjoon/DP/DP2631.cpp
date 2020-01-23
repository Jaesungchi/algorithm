#include <iostream>
using namespace std;

//[줄 세우기 난이도★★](https://www.acmicpc.net/problem/2631)

int N; //학생 수
int map[201];
int tmpM[201];

int LIS() {
	int maxs = 1;
	for (int i = 1; i < N; i++) {
		tmpM[i] = 1;
		for (int j = i + 1; j <= N; j++) {
			int maxI = i;
			if (map[j] <= map[i]) continue;
			for (int k = j - 1; k >= i; k--) {
				if (map[k] >= map[j]) continue;
				if (tmpM[maxI] < tmpM[k])
					maxI = k;
			}
			tmpM[j] = tmpM[maxI] + 1;
			if (maxs < tmpM[j])
				maxs = tmpM[j];
		}
	}
	return maxs;
}

int main() {
	int tmp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		map[i] = tmp;
	}
	cout << N - LIS() << "\n";
}