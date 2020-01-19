#include <iostream>
#include <algorithm>
using namespace std;

//[전구 난이도★★★★](https://www.acmicpc.net/problem/2449)

int N, K;// 전구 수 N < 200 , 전구 색 K < 20
int map[201];
int DP[201][201]; 

int DFS(int start, int end) {
	if (start == end) return 0; //같다면 횟수는 0
	if (DP[start][end] != -1) return DP[start][end]; //계산한 적이 있다면
	DP[start][end] = 9999999;
	for (int i = start; i < end; i++) { //메모리 제이션 이용
		int notSame = map[start] != map[i + 1] ? 1 : 0; //다르다면 횟수 1 추가
		DP[start][end] = min(DP[start][end], DFS(start, i) + DFS(i + 1, end) + notSame); //재귀로 들어간다.
	}
	return DP[start][end];
}

void setDP() {
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ;j++)
			DP[i][j] = -1;
}

int main() {
	int counts = 0; //변화가 제일 큰 Index를 가져옴
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	setDP();
	cout << DFS(0, N - 1) << "\n";
}