#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1019 //å ������ ���̵� �ڡڡڡ� 

long long N, arr[10] = { 0, };
int start = 1,point = 1;

int main() {
	cin >> N;
	while (start <= N) {
		//���ڸ� 9�� ����� ����ϱ� ����
		while (N % 10 != 9 && start <= N) {
			long long tmp = N;
			while (tmp > 0) {
				arr[tmp % 10] += point;
				tmp /= 10;
			}
			N--;
		}
		if (N < start) break;

		//�����ڸ� 0�� ����� ����ϱ� ����
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