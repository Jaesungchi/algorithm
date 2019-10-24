#include <iostream>
using namespace std;

void start() {
	int n, arr[201], data[201], tmp = 0, saves;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int counts = 1, checks = arr[i]; //counts 몇회? checks 는 다음건 어딘지.
		while (true) {
			if (checks - 1 == i) //돌아 온다면.
				break;
			counts++;
			checks = arr[checks - 1];
		}
		data[i] = counts;
	}
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << "\n";
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		start();
}