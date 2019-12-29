#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11726 2xn 타일링
//규칙을 찾으면 할 수 있음.
//오버 되는것을 막기 위해  %를 계속 해줘야함
// A%b + C%b == (A + C)%b 이다. 

int visit[1001];

int main() {
	int N;
	cin >> N;
	visit[1] = 1;
	visit[2] = 2;
	for (int i = 3; i <= N; i++) {
		visit[i] = visit[i - 1] + visit[i - 2];
		visit[i] %= 10007;
	}
	cout << visit[N];
}