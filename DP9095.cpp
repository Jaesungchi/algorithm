#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/9095 1,2,3 ´õÇÏ±â

int datas[11] = { 0,1,2,4 , };

int main() {
	int N, temp;
	cin >> N;
	for (int i = 4; i <= 10; i++) {
		datas[i] = datas[i - 1] + datas[i - 2] + datas[i - 3];
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cout << datas[temp] << "\n";
	}
}