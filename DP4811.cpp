#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/4811 �˾�
//�ݺ����� �ʰ� �̹� �鷶�� DP�� �鸮�� �ʰ� �ؾ���.
//DP�� �μ����� �ִ°� �ƴ� W H ���� �����.

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