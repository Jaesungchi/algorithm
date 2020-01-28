#include <iostream>
#include <cstdlib>
using namespace std;

//[맥주 마시면서 걸어가기 난이도★★](https://www.acmicpc.net/problem/9205)

typedef struct location {
	int x, y;
}L;

int Pc; //편의점 수
L P[103];// 편의점
bool check[101];

void resetRun() {
	for(int i = 0; i < 101; i++)
		check[i] = false;
}

//병맥주 계산하는 함수
int distance(L t1, L t2) {
	int sum = 0;
	sum += abs(t1.x - t2.x);
	sum += abs(t1.y - t2.y);
	return sum;
}

bool DFS(int now) {
	if (now == Pc) return true; //도착
	check[now] = true;
	for (int i = 1; i <= Pc; i++) {
		if (check[i]) continue; //들렀던 편의점 넘어감.
		int distB = distance(P[now], P[i]);
		if (distB <= 1000 && DFS(i))
				return true;
	}
	return false;
}

bool run() {
	resetRun();
	cin >> Pc;
	Pc += 1;
	for (int i = 0; i <= Pc; i++)
		cin >> P[i].x >> P[i].y;
	return(DFS(0));
}

int main() {
	int t;//test 케이스
	cin >> t;
	while (t--)
		if (run())
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
}