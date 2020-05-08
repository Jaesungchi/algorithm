#include <iostream>
#include <queue>
using namespace std;

//[숨바꼭질 3 난이도★★](https://www.acmicpc.net/problem/13549)

/*
	엄한데서 해맨 문제...
*/

int n, k;
int chk[100001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < 100001; i++)
		chk[i] = 999999999;
	chk[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == k) {
			cout << chk[now] << "\n";
			break;
		}
		//현재에서 -1 , 1 을한다.
		if (now + 1 <= 100000 && chk[now + 1] > chk[now] + 1) {
			q.push(now+1);
			chk[now + 1] = chk[now] + 1;
		}
		if (now - 1 >= 0 && chk[now - 1] > chk[now] + 1) {
			q.push(now - 1);
			chk[now - 1] = chk[now] + 1;
		}
		//2배를 한다.
		if (now * 2 < 100001 && chk[now * 2] > chk[now]) {
			q.push(now*2);
			chk[now * 2] = chk[now] ;
		}
	}
}