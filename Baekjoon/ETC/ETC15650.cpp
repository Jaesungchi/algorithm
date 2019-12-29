#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15650 NXM (2)

int N, M, tmps[8];
bool arr[10001];

void Run(int min, int counts) {
	if (counts == M) {
		for (int i = 0; i < M; i++)
			cout << tmps[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = min; i <= N; i++) {
		if (arr[i])
			continue;
		arr[i] = true;
		tmps[counts] = i;
		Run(i + 1, counts + 1);
		arr[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;
	cin >> N >> M;
	Run(1, 0);
}