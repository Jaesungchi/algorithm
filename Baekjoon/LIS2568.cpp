#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maps[500001];
int mapB[500001];
int DP[100001];
int save[100001];

int main() {
	int tmp1, tmp2,tsave=0,length = 1,maxI = 0,minI = 500001;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		maps[tmp1] = tmp2;
		mapB[tmp2] = tmp1;
		maxI = maxI > tmp1 ? maxI : tmp1;
		minI = minI < tmp1 ? minI : tmp1;
	}
	DP[1] = maps[minI];
	for (int i = minI+1; i <= maxI; i++) {
		if (maps[i] == 0) continue;
		if (DP[length] < maps[i]) {
			DP[++length] = maps[i];
			continue;
		}
		tmp1 = lower_bound(DP + 1, DP + length + 1, maps[i]) - DP;
		save[tsave++] = mapB[DP[tmp1]];
		DP[tmp1] = maps[i];
	}
	cout << N - length << "\n";
	for (int i = 0; i < tsave; i++)
		cout << save[i] << "\n";
}