#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//[휴게소 세우기 난이도★★★](https://www.acmicpc.net/problem/1477)

int N, M, L; // N, M <= 100, 100 <= L <= 1000
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp, left = 0, right = 0, mid,mindis = 1000;
	cin >> N >> M >> L;
	arr.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	arr.push_back(L);
	sort(arr.begin(), arr.end());
	for (int i = 1; i < arr.size(); i++) {
		int tmp = arr[i] - arr[i-1];
		mindis = min(mindis, tmp);
		right = max(right, tmp);
	}

	while (left <= right) {
		mid = (left + right) / 2;
		tmp = 0;
		for (int i = 1; i < arr.size(); i++)
			tmp += (arr[i] - arr[i - 1] - 1) / mid;
		if (tmp > M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;
}