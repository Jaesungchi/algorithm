#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//[행성탐사 난이도★★](https://www.acmicpc.net/problem/5549)

int N, M, K; //가로 N 세로 M
int datas[1001][1001][3];
string arr[1001]; //정글은 J 바다는 O 얼음은 I

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != 0) //위에를 더함
				for(int k = 0 ; k < 3; k++)
					datas[i][j][k] += datas[i - 1][j][k];
			if (j != 0)
				for (int k = 0; k < 3; k++)
					datas[i][j][k] += datas[i][j - 1][k];
			if (i != 0 && j != 0)
				for (int k = 0; k < 3; k++)
					datas[i][j][k] -= datas[i - 1][j - 1][k];
			if (arr[i-1][j-1] == 'J')
				datas[i][j][0]++;
			else if (arr[i-1][j-1] == 'O')
				datas[i][j][1]++;
			else
				datas[i][j][2]++;
		}
	}

	while (K--) {
		int a, b, c, d;
		int J = 0, O = 0, I = 0;
		cin >> a >> b >> c >> d;
		J = datas[a - 1][b - 1][0] - datas[c][b - 1][0] - datas[a - 1][d][0] + datas[c][d][0];
		O = datas[a - 1][b - 1][1] - datas[c][b - 1][1] - datas[a - 1][d][1] + datas[c][d][1];
		I = datas[a - 1][b - 1][2] - datas[c][b - 1][2] - datas[a - 1][d][2] + datas[c][d][2];
		cout << J << " " << O << " " << I << "\n";
	}
}