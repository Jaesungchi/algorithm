#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15655 NXM (6)

int N, M, tmps[8];
bool arr[10001];

void Run(int min, int counts) {
	if (counts == M) {
		for (int i = 0; i < M; i++)
			cout << tmps[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = min; i < 10000; i++) {
		if (arr[i]) {
			tmps[counts] = i;
			arr[i] = false;
			Run(i, counts + 1);
			arr[i] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[temp] = true;
	}
	Run(0, 0);
}