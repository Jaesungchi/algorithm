#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1149 RGB거리

//동적 계획법 으로 시간 초과를 조심해야하며 DP로 풀어야한다.
//dfs로 풀면 시간 초과 되므로 풀수 없음.
//다음 값부터 시작해서 미리 첫번째부터가 아닌 두번째 부터 값을 누적해서 저장하면서 한다.
//쉬워보이지만 개념이 어려운 문제
int N, map[1001][3] = { 0,0,0, }, dP[1001][3] = { 0,0,0, };

int min(int x,int y) {
	return x < y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];
	for (int i = 1; i <= N; i++) {
		dP[i][0] = min(dP[i - 1][1], dP[i - 1][2]) + map[i][0];
		dP[i][1] = min(dP[i - 1][0], dP[i - 1][2]) + map[i][1];
		dP[i][2] = min(dP[i - 1][0], dP[i - 1][1]) + map[i][2];
	}
	cout << min(min(dP[N][0],dP[N][1]),dP[N][2]);
}