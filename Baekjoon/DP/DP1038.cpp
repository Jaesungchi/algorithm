#include <iostream>
#include <math.h>
using namespace std;

//[감소하는 수 난이도★★★](https://www.acmicpc.net/problem/1038)

int N;
int DP[10][10][500];

void foundIndex(int *counts, int *y, int *x) {
	while (true) {
		for (*y = 0; *y < 10; (*y)++) {
			for (*x = 0; *x < 10; (*x)++) {
				*counts += DP[*y][*x][0];
				if (*counts > N) {
					*counts -= DP[*y][*x][0];
					return;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		DP[0][i][0] = 1; //1의자리 i는 1
		DP[0][i][1] = i; //그 값을 넣어둔다.
	}
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 10; j++) {
			int insert = 1;
			for (int k = 0; k < j; k++) {
				DP[i][j][0] += DP[i - 1][k][0]; //0번째에는 갯수 저장
				int tmp = pow(10, i)*j;
				for (int z = 1; z <= DP[i - 1][k][0]; z++) {
					DP[i][j][insert++] = tmp + DP[i - 1][k][z];
				}
			}
		}
	int tmp = 0;
	int counts = 0,y= 0,x=0;
	foundIndex(&counts,&y,&x);
	if (1022 < N)
		cout << -1 << "\n";
	else if (1022 == N)
		cout << 9876543210 << "\n";
	else {
		int i = 1;
		while (counts != N) {
			counts++;
			tmp = DP[y][x][++i];
		}
		tmp = DP[y][x][i];
		cout << tmp;
	}
}