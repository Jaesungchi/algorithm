#include <iostream>
using namespace std;

void start() {
	int n, arr[101], check = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[j] - arr[i] == 1 || arr[j] - arr[i] == -1)
				check = 2;
	cout << check << "\n";
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		start();
	}
}