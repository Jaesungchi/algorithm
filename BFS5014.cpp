#include <iostream>
#include <queue>
using namespace std;

//https://www.acmicpc.net/problem/5014 ��ŸƮ��ũ
//BFS ������ ť�� Ȱ���ϴ°� ���ٴ°��� �˰Ե� ����

int F, G, S, U, D;
int visitfloor[1000001];

int main() {
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++)
		visitfloor[i] = -1;

	queue<int> q;
	q.push(S);
	visitfloor[S] = 0;
	//�鷶�� ���� �����͸� �����س��� �ι� �ȵ鸮�� �����
	//�鷶�� ���� �����ϴ� ���� �󸶳� ������ �鷶���� �� �� ����.
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