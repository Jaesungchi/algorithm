#include <iostream>
using namespace std;

//[제곱 ㄴㄴ 수 난이도★★★★](https://www.acmicpc.net/problem/1016)

bool numbers[1000001];

long long mins, maxs;

int main() {
	cin >> mins >> maxs;
	long long ans = maxs - mins + 1;
	//범위를 mins ~ maxs로 잡고 시간을 단축시켰다.
	for (long long i = 2; i * i <= maxs; i++) { 
		long long start = mins % (i * i) == 0 ? 0 : i * i - (mins % (i * i));
		for (long long j = start; j <= maxs - mins; j += i * i)
			if (!numbers[j]) { 
				ans -= 1; 
				numbers[j] = true; 
			}
	}
	cout << ans << '\n';
}