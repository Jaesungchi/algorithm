#include <iostream>
#include <vector>
using namespace std;

//[스도쿠 난이도★★★](https://www.acmicpc.net/problem/2580)

int arr[9][9];
int arrStart[9] = { 0,0,0,3,3,3,6,6,6 };
int arrEnd[9] = { 2,2,2,5,5,5,8,8,8 };
vector<pair<int, int>> q;
bool endRun = false;

bool isGood(int y, int x) {
	//가로,세로를 확인한다.
	for (int i = 0; i < 9; i++) {
		if (x != i && arr[y][i] == arr[y][x])
			return false;
		if (y != i && arr[i][x] == arr[y][x])
			return false;
	}
	//3x3칸을 확인한다.
	for (int i = arrStart[y]; i <= arrEnd[y]; i++)
		for (int j = arrStart[x]; j <= arrEnd[x]; j++)
			if (x != j && y != i && arr[i][j] == arr[y][x])
				return false;
	return true;
}

void bt(int idx) {
	if (endRun)
		return;
	if (idx == q.size()) {
		//출력한다.
		endRun = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
		return;
	}
	if (idx >= q.size())
		return;
	int y = q[idx].first, x = q[idx].second;
	for (int i = 1; i <= 9; i++) {
		arr[y][x] = i;
		if (isGood(y, x))
			bt(idx + 1);
		arr[y][x] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				q.push_back(make_pair(i, j));
		}
	bt(0);
}