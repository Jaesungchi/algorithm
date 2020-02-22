#include <iostream>
#include <algorithm>
using namespace std;

//[수 찾기 난이도★(이분탐색)](https://www.acmicpc.net/problem/1920)

int N, M;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int find;
		cin >> find;
		if (binary_search(arr, arr + N, find))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}