#include <iostream>
#include <queue>
#include <string>
using namespace std;

//[DSLR 난이도★★](https://www.acmicpc.net/problem/9019)

bool visit[10001];

typedef struct Data {
	int data;
	string menu;
}D;

void resetVisit() {
	for (int i = 0; i < 10000; i++)
		visit[i] = false;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase-- > 0) {
		int A, B;
		cin >> A >> B;
		resetVisit();
		queue<D> q;
		q.push({ A,"" });
		visit[A] = true;
		while (!q.empty()) {
			D now = q.front();
			if (now.data == B)
				break;
			q.pop();
			//D를 한다.
			D tmp = now;
			tmp.data = (tmp.data * 2) % 10000;
			if (!visit[tmp.data]) {
				tmp.menu += 'D';
				q.push(tmp);
				visit[tmp.data] = true;
			}
			//S를 한다.
			tmp = now;
			if (tmp.data == 0)
				tmp.data = 9999;
			else
				tmp.data -= 1;
			if (!visit[tmp.data]) {
				tmp.menu += 'S';
				q.push(tmp);
				visit[tmp.data] = true;
			}
			//L을 한다.
			tmp = now;
			tmp.data *= 10;
			int carry = tmp.data / 10000;
			tmp.data = (tmp.data % 10000) + carry;
			if (!visit[tmp.data]) {
				tmp.menu += 'L';
				q.push(tmp);
				visit[tmp.data] = true;
			}
			//R을 한다.
			tmp = now;
			carry = tmp.data % 10;
			tmp.data = tmp.data / 10 + carry * 1000;
			if (!visit[tmp.data]) {
				tmp.menu += 'R';
				q.push(tmp);
				visit[tmp.data] = true;
			}
		}
		cout << q.front().menu << "\n";
	}
}