#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15652 NXM (4)

int N, M, tmps[8];

void Run(int min,int counts) {
	if (counts == M) {
		for (int i = 0; i < M; i++)
			cout << tmps[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = min; i <= N; i++) {
		tmps[counts] = i;
		Run(i,counts + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;
	cin >> N >> M;
	Run(1,0);
}