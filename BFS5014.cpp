#include <iostream>
#include <queue>
using namespace std;

//https://www.acmicpc.net/problem/5014 스타트링크
//BFS 문제는 큐를 활용하는게 좋다는것을 알게된 문제

int F, G, S, U, D;
int visitfloor[1000001];

int main() {
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++)
		visitfloor[i] = -1;

	queue<int> q;
	q.push(S);
	visitfloor[S] = 0;
	//들렀던 곳은 데이터를 저장해놔서 두번 안들리게 만들고
	//들렀던 곳을 저장하는 곳에 얼마나 빠르게 들렀는지 알 수 있음.
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		if (idx + U <= F && visitfloor[idx + U] == -1) {
			q.push(idx + U);
			visitfloor[idx + U] = visitfloor[idx] + 1;
		}
		if (idx - D >0 && visitfloor[idx - D] == -1) {
			q.push(idx - D);
			visitfloor[idx - D] = visitfloor[idx] + 1;
		}
	}
	if (visitfloor[G] != -1)
		cout << visitfloor[G];
	else
		cout << "use the stairs";
}