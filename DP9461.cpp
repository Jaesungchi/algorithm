#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/9461 파도반 수열
//int 사이즈로는 다 못받는 다는걸 생각해야 함

int T, temp;
long long DP[102] = { 0,1,1,1,2,2,3, };

int main() {
	cin >> T;
	for (int i = 5; i < 101; i++)
		DP[i] = DP[i - 1] + DP[i - 5];
	for (int i = 0; i < T; i++) {
		cin >> temp;
		cout << DP[temp] << "\n";
	}
}