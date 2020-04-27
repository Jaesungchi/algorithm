#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//[기타 레슨 난이도★★](https://www.acmicpc.net/problem/2343)

int N, M; //1<= N <= 100,000 1 <= M <= N
vector<int> arr; //영상은 10000분

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp,left = 0,right = 0, mid;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		right += tmp;
		left = max(left, tmp);
	}

	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		tmp = 0;
		for (int i = 0; i < N; i++) {
			if (tmp + arr[i] > mid) {
				tmp = 0;
				cnt++;
			}
			tmp += arr[i];
		}
		if (tmp > 0)
			cnt++;
		if (cnt > M)
			left = mid + 1;
		else if (cnt <= M) {
			right = mid - 1;
		}
	}
	cout << left;
}