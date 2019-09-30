#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15663 NXM (9)

int N, M, tmps[8];
int arr[10001];

void Run(int counts) {
	if (counts == M) {
		for (int i = 0; i < M; i++)
			cout << tmps[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < 10000; i++) {
		if (arr[i] > 0) {
			tmps[counts] = i;
			arr[i] -= 1;
			Run(counts + 1);
			arr[i] += 1;
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
		arr[temp] += 1;
	}
	Run(0);
}