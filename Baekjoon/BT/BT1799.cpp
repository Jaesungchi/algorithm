#include <iostream>
#include <algorithm>
using namespace std;

//[비숍 난이도★★★](https://www.acmicpc.net/problem/1799)
/*
	색깔을 구분해서 계산할 수 있게 하는것이 중요.
	안그러면 시간초과남.
	10초 나 주는데도 시간초과가 나네.
*/

int N; // 10이하의 자연수
int arr[11][11];
int ans[2];
int l[20], r[20]; //대각에 놓을 수 있는지.

void BT(int row, int col, int count, int color) {
	if (col >= N) {
		row++;
		if (col % 2 == 0) col = 1;
		else col = 0;
	}
	if (row >= N) {
		ans[color] = max(ans[color], count);
		return;
	}

	if (arr[row][col] && !l[col - row + N - 1] && !r[row + col]) {
		l[col - row + N - 1] = r[row + col] = 1;
		BT(row, col + 2, count + 1, color);
		l[col - row + N - 1] = r[row + col] = 0;
	}
	BT(row, col + 2, count, color);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	BT(0, 0, 0, 0);
	BT(0, 1, 0, 1);

	cout << ans[0] + ans[1] << "\n";
	return 0;
}