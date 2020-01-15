#include <iostream>
#include <queue>
using namespace std;

//[프린터 큐](https://www.acmicpc.net/problem/1966)

typedef struct data {
	int index;
	int imp;
}D;

void run() {
	int N, M, tmp,counts = 0;
	queue<D> q;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		D news = { i,tmp };
		q.push(news);
	}
	while (true) {
		D tmp = q.front();
		q.pop();
		queue<D> tmpQ;
		while (!q.empty()) {
			if (tmp.imp >= q.front().imp) { //순위가 낮은경우
				tmpQ.push(q.front());
				q.pop();
				continue;
			}
			q.push(tmp); //나보다 큰게 있는경우
			break;
		}
		if (q.empty()) { //현재 나온게 순위가 제일 높다면
			counts += 1;
			if (tmp.index == M) { //내가 뽑을 숫자라면
				cout << counts << "\n";
				return;
			}
		}
		else {
			while (!q.empty()) {
				tmpQ.push(q.front());
				q.pop();
			}
		}
		q = tmpQ;
	}
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
		run();
}