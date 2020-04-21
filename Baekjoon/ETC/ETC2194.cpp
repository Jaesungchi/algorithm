#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;

//[홍준 프로그래밍 대회 난이도★★★](https://www.acmicpc.net/problem/1222)

ll x, res, a[2000020];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= 2000000; i++) {
		ll cnt = 0;
		for (int j = i; j <= 2000000; j += i)
			cnt += a[j];
		if (cnt > 1)
			res = max(res, cnt*i);
	}
	cout << res << "\n";
}