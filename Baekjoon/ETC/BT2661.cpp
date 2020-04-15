#include <iostream>
using namespace std;

//[좋은수열 난이도★★](https://www.acmicpc.net/problem/2661)

int n;
int arr[100];

//진위 여부 판단.
bool isGood(int index) {
	int counts = 0;
	for (int i = 2; i <= index / 2; i++) {
		for (int j = 1; j <= index - i; j++) {
			counts = 0;
			for (int k = j; k < i + j; k++) {
				if (i + k > index)
					continue;
				if (arr[k] == arr[i + k])
					counts++;
			}
			if (counts == i)
				return false;
		}
	}
	return true;
}

void inserts(int index) {
	if (index > n) {
		for (int i = 1; i <= n; i++)
			cout << arr[i];
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[index - 1] == i)
			continue;
		arr[index] = i;
		if (isGood(index))
			inserts(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	inserts(1);
	
}