#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/4811 알약
//반복되지 않게 이미 들렀던 DP는 들리지 않게 해야함.
//DP가 인수마다 주는게 아닌 W H 마다 줘야함.

int temp;
long long DP[31][31];

long long DFS(int W, int H) {
	if (W == 0 && H == 0) {
		return 1;
	}
	if (DP[W][H] != 0) {
		return DP[W][H];
	}
	if (W == 0)
		DP[W][H] = DFS(W, H - 1);
	else if (H == 0)
		DP[W][H] = DFS(W - 1, H + 1);
	else 
		DP[W][H] = DFS(W - 1, H + 1) + DFS(W, H - 1);
	return DP[W][H];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> temp;
	while(temp != 0){
		cout << DFS(temp,0) << "\n";
		cin >> temp;
	}
}