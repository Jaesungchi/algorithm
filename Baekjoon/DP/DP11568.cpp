#include<iostream>
using namespace std;

//[민균이의 계략 난이도★★](https://www.acmicpc.net/problem/11568)

int N;
int arr[1001];
int DP[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int maxs = 1;
	DP[0] = 1; //0번째 숫자는 최초다.
	for (int i = 1; i < N; i++) {
		int maxCount = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] <= arr[j]) continue;
			if (DP[j] > maxCount)
				maxCount = DP[j];
		}
		DP[i] = ++maxCount;
		if (maxCount > maxs)
			maxs = maxCount;
	}
	cout << maxs;
}