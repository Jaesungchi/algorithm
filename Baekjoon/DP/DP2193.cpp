#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2193 ÀÌÄ£¼ö

long long datas[91] = {0,1,1,2,3, };

int main() {
	long long N, sums = 0;
	cin >> N;
	for (int i = 5; i <= N; i++) {
		for (int j = i - 2; j >= 0; j--) {
			datas[i] += datas[j];
		}
		datas[i]++;
	}
	cout << datas[N];
}