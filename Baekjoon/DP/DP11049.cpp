#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;

//[행렬 곱셈 순서 난이도★★★](https://www.acmicpc.net/problem/11049)
//메모이제이션 이용.

int N;
int map[501][2];
int DP[501][501];

int run(int start,int end){
	if (start == end) return 0; //같으면 0

	int &ref = DP[start][end]; //주소를 저장해 둔다. 시간 절약

	if (ref != -1) return ref; //이미 값이 있다면

	int mmax = INT_MAX;
	for (int i = start; i < end; i++) 
		mmax = min(mmax, run(start, i) + run(i + 1, end) + map[start][0] * map[i][1] * map[end][1]);
	return ref = mmax;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> map[i][0] >> map[i][1];
	memset(DP, -1, sizeof(DP)); //-1로 세팅

	cout << run(1, N) << "\n";
}