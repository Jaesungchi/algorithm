#include <iostream>;
using namespace std;

//https://www.acmicpc.net/problem/1699 제곱수의 합
//시간이 너무 오래걸린다 ;; 방법이 있을듯

int N, temp, counts, datas[100002] = { 0,1,2,3, };

int main() {
	cin >> N;
	for (int i = 4; i <= N; i++) {
		datas[i] = 9999999;
		for (int j = 2; j* j <= i; j++) {
			temp = i;
			counts = 0;
			if (temp >= j * j) {
				while (temp >= j * j) {
					temp -= j * j;
					counts += 1;
				}
				counts += datas[temp];
			}
			else
				break;
			datas[i] = datas[i] < counts ? datas[i] : counts;
		}
	}
	cout << datas[N];
}