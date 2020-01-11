#include <iostream>
using namespace std;
//[리모콘 난이도 ★★★★](https://www.acmicpc.net/submit/1107)

int N, counts = 0,mokpyo1 = 0, mokpyo2 = 0;
bool can[10] = { false };

bool isCanGo(int num) {
	int saves = num;
	while (saves > 0) {
		int temp = saves % 10;
		if (can[temp]) //가지 못하는 경우
			return false;
		saves /= 10;
	}
	return true;
}

int countSize(int num) {
	int sum = 0;
	if (num == 0)
		return 1;
	while (num > 0) {
		num /= 10;
		sum += 1;
	}
	return sum;
}

int main() {
	int temp,temp2;
	cin >> N;
	cin >> temp;
	for (int i = temp; i > 0; i--) { //금지 숫자를 받는다.
		cin >> temp2;
		can[temp2] = true;
	}
	if (N == 100) {
		cout << 0 << "\n";
		return 0;
	}
	counts = abs(100 - N);
	for (int i = 0; i <= 1000000; ++i) {
		if (isCanGo(i)) {
			int len = countSize(i);
			counts = abs(N - i) + len < counts ? abs(N - i) + len : counts;
		}
	}
	cout << counts << "\n";
}