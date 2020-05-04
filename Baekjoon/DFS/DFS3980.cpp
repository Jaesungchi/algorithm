#include <iostream>
#include <vector>
using namespace std;

//[선발명단 난이도★](https://www.acmicpc.net/problem/3980)
/*
	그렇게 어렵지 않은 문제.
	최대 11! 만큼 걸린다.
*/

int output = 0;

void dfs(vector<vector<int>> arr, int index, int point,vector<bool> chk) {
	if (index == 11) {
		output = output < point ? point : output;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (arr[i][index] == 0 || chk[i])
			continue;
		chk[i] = true;
		dfs(arr, index + 1, point + arr[i][index],chk);
		chk[i] = false;
	}
}

void run() {
	vector<vector<int>> arr;
	vector<bool> chk;
	int tmp;
	output = 0;
	for (int i = 0; i < 11; i++) {
		vector<int> tmpVector;
		for (int j = 0; j < 11; j++) {
			cin >> tmp;
			tmpVector.push_back(tmp);
		}
		arr.push_back(tmpVector);
		chk.push_back(false);
	}
	dfs(arr, 0, 0,chk);
	cout << output << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		run();
}