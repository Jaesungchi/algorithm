#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/2133 Ÿ��ä���
//��Ģ ã�Ⱑ �ſ� ���� 3�� �Ǵϱ� ��찡 �ʹ� ���� ;;

int N, datas[31] = { 1,0,3,0,11, };

int main() {
	cin >> N;
	for (int i = 5; i <= N; i++)
		if (i % 2 == 1)
			datas[i] = 0;
		else {
			datas[i] = datas[i-2]*3;
			for (int j = 4; i - j >= 0; j += 2)
				datas[i] += datas[i - j] * 2;
		}
	cout << datas[N]<<"\n";
}