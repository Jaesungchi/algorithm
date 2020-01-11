#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1019 //책 페이지 난이도 ★★★★ 

long long N, arr[10] = { 0, };
int start = 1,point = 1;

int main() {
	cin >> N;
	while (start <= N) {
		//끝자리 9로 만들기 계산하기 쉽게
		while (N % 10 != 9 && start <= N) {
			long long tmp = N;
			while (tmp > 0) {
				arr[tmp % 10] += point;
				tmp /= 10;
			}
			N--;
		}
		if (N < start) break;

		//시작자리 0로 만들기 계산하기 쉽게
		while (start % 10 != 0 && start <= N) {
			long long tmp = start;
			while (tmp > 0) {
				arr[tmp % 10] += point;
				tmp /= 10;
			}
			start++;
		}

		start /= 10;
		N /= 10;

		for (int i = 0; i < 10; i++)
			arr[i] += (N - start + 1) * point;
		point *= 10;
	}
	for (int i = 0; i <= 9; i++)
		cout << arr[i] << " ";
	cout << "\n";
}