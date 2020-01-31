#include <iostream>
#include <algorithm>
using namespace std;

//[색종이붙이기 난이도★★★](https://www.acmicpc.net/problem/17136)
//그리디로 접근했으나 실패함, BF로 접근해야하는듯.

int page[6];
int map[11][11]; //-1은 아직 아무것도 안한칸
int maxP = 26;

//y x 좌표에서 어떤 사이즈 종이랑 맞는지비교.
bool compare(int x, int y, int size) {
	bool flag = true;
	if (x + size > 10 || y + size > 10) return false; //맵을 나가는 사이즈
	for (int j = 0; j < size; j++)
		for (int k = 0; k < size; k++)
			if (map[y + j][x + k] == 0)
				return false;
	return true;
}

void run(int x, int y,int counts) {
	if (x == 10) {
		run(0, y + 1,counts);
		return;
	}
	if (y == 10) {
		maxP = min(maxP, counts);
		return;
	}
	if (map[y][x] == 0) { //빈자리 확인 안함
		run(x + 1, y, counts);
		return;
	}
	for (int k = 5; k > 0; k--) { //제일 큰사이즈부터 들어가는지 확인
		if (!compare(x, y, k) || page[k] >= 5) continue;
		for (int i = y; i < y + k; i++)
			for (int j = x; j < x + k; j++)
				map[i][j] = 0;
		page[k]++;
		run(x + 1, y, counts+1);
		for (int i = y; i < y + k; i++)
			for (int j = x; j < x + k; j++)
				map[i][j] = 1;
		page[k]--;
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	//제일 큰 종이부터 들어갈 수 있는지 확인한다.
	run(0,0,0);
	if (maxP == 26)
		cout << -1  << "\n";
	else
		cout << maxP << "\n";
}