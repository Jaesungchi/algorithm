#include <iostream>
#include <algorithm>
using namespace std;

//[저울 난이도★★](https://www.acmicpc.net/problem/2437)
// 1부터 계속 만들수 있나 했더니 시간초과 뜸.

int N; //1 < N <= 1000
int arr[1001];

int run() {
	int sum = 1;
	for (int i = 0; i < N; i++) {
		if (sum < arr[i]) break;
		sum += arr[i];
	}
	return sum;
}

int main() {
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N); //최소값부터 정렬
	cout << run() << "\n";
}