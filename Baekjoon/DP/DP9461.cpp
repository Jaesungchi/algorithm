#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/9461 �ĵ��� ����
//int ������δ� �� ���޴� �ٴ°� �����ؾ� ��

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