#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10989 �� �����ϱ� 3
//���� ���������� �˾Ҵµ� �޸𸮹��� �ɰ���. ���� 10000000���� �迭�� ������
//������ ��Ʈ�� �־���.

int n, datas[10001],temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		datas[temp] ++;
	}

	for (int i = 1; i < 10001; i++)
		for(int j = 1; j <= datas[i];j++)
			cout << i << "\n";
}