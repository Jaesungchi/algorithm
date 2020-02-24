#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//[624_B](https://codeforces.com/contest/1311/problem/B)

//문제 nArr에 든 원소가 정렬이 가능하면 YES 아니면 NO
//mArr에 든 원소는 회전이 가능하다 알려주는 원소.
//mArr에 1이 들었으면 nArr[0] <-> nArr[1]이 가능

/*
해결방법
각원소들의 원래 자리를 파악하고 오른쪽으로 가야한다면
자기 자리의 오른쪽으로 가는 mArr들이 있어야하고 
(오른쪽은 자기 위치+1 부터 도착지까지)
왼쪽은 왼쪽으로 가는 mArr이 있어야함.
(왼쪽은 자기 위치값부터 도착지 +1 까지)
*/

typedef struct good {
	int gap;
	int pos;
}G;

int n, m; //n 사이즈 ,m 사이즈
int nArr[101];
G good[101];
int mArr[101];

bool haverightMArr(int i, int findIndex) {
	//(오른쪽은 자기 위치+1 부터 도착지까지)
	for (int j = i+1; j <= findIndex; j++) {
		bool checks = true;
		//찾아야할 값 j
		for (int k = 0; k < m; k++)
			if (j == mArr[k]) {
				checks = false;
				break;
			}
		if (checks)
			return false; //찾지 못함
	}
	return true; //찾음
}

bool haveleftMArr(int i,int findIndex) {
	//(왼쪽은 자기 위치값부터 도착지 +1 까지)
	for (int j = i; j > findIndex; j--) {
		bool checks = true;
		//찾아야할 값 j
		for (int k = 0; k < m; k++)
			if (j == mArr[k]) {
				checks = false;
				break;
			}
		if (checks)
			return false; //찾지 못함
	}
	return true; //찾음
}

bool compare(G a, G b) {
	return a.gap < b.gap;
}

void run() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nArr[i];
		good[i].gap = nArr[i];
		good[i].pos = i; //원래 위치
	}
	sort(good, good + n,compare);
	for (int i = 0; i < m; i++)
		cin >> mArr[i];
	//여기서부터 찾기 시작
	for (int i = 0; i < n; i++) {
		//nArr[i]의 값의 위치를 찾는다.
		if (i == good[i].pos) //원래 위치는 패스
			continue;
		//원래 위치에서 현재 위치로 올 수있는지 본다.
		if (good[i].pos < i) { //왼쪽으로 가야하는경우
			if(!haveleftMArr(i,good[i].pos)){
				cout << "NO\n";
				return;
			}
		}
		else { //오른쪽으로 가야하는 경우
			if (!haverightMArr(i, good[i].pos)) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
		run();
}