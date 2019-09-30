#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/15657 NXM (8)

int N, M, tmps[8], maxs = 0;

void Run(int min, int counts, vector<int> arr) {
	if (counts == M) {
		for (int i = 0; i < M; i++)
			cout << tmps[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = min; i < N; i++) {
		tmps[counts] = arr[i];
		Run(i, counts + 1, arr);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr.begin(), arr.end());
	Run(0, 0, arr);
}