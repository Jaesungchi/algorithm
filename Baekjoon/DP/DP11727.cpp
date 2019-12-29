#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11727 2xn Å¸ÀÏ¸µ 2

int vec[1001];

int main() {
	int N;
	cin >> N;
	vec[1] = 1;
	vec[2] = 3;
	for (int i = 3; i <= N; i++)
		vec[i] = (vec[i - 1] + vec[i - 2] * 2) % 10007;
	cout << vec[N];
}