#include <iostream>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/2751 �������ϱ�2
//���� �����Ʈ�� �ð� �ʰ� ��
//�˰��� ���̺귯���� sort�� �� Ȱ������.
//solve : 17:25 //�˻��� ��...

int N, datas[1000001], temp;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i];
	sort(datas, datas + N);
	for (int i = 0; i < N; i++)
		cout << datas[i] << "\n";
	return 0;
}