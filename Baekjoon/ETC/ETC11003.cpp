#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//[최솟값 찾기](https://www.acmicpc.net/problem/11003)
//슬라이딩 윈도우 기법 사용.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, tmp;
	deque<pair<int,int>> arr;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (arr.size() && arr.front().second <= i - x) arr.pop_front();
		while (arr.size() && arr.back().first >= tmp) arr.pop_back();
		arr.push_back({ tmp, i });
		cout << arr.front().first << " ";
	}
}