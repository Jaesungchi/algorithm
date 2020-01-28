#include <iostream>
#include <algorithm>
using namespace std;

//[택배 난이도★★★](https://www.acmicpc.net/problem/8980)
//맨처음에는 일반적으로 다싣고 넘어가고 했는데 이러니 안됨.
//그리디 답게 마을거리가 짧은거 부터 싣고 넘어가는 식으로 변경

typedef struct order {
	int start, end, box;
}O;

int N, mBox;
int runTime; //이벤트가 있는 개숫
O order[10001];
int box[2001]; //마을마다 도착할 박스

bool compare(O a, O b) {
	if (a.end != b.end)
		return a.end < b.end; //오름차순
	return a.start < b.start; //가까운곳 부터
}

int main() {
	cin >> N >> mBox;
	cin >> runTime;
	for (int i = 0; i < runTime; i++)
		cin >> order[i].start >> order[i].end >> order[i].box;
	sort(order, order + runTime, compare);

	int sum = 0;
	for (int i = 0; i < runTime; i++) {
		int countBox = 0;
		for (int j = order[i].start; j < order[i].end; j++)
			countBox = max(countBox, box[j]); //가장 많이 적재된걸 찾는다.
		int inBox = min(mBox - countBox, order[i].box);
		sum += inBox;
		for (int j = order[i].start; j < order[i].end; j++)
			box[j] += inBox;
	}
	cout << sum << "\n";
}