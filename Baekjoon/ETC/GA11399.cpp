#include <vector>
#include <iostream>
using namespace std;
//�׸��� �˰��� ����
//https://www.acmicpc.net/problem/11399 ATM

int main() {
	int N,tmp,sums = 0;
	vector<int> arr; //�����͸� ������ ����
	vector<bool> arrbool;
	vector<int> outs;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		arrbool.push_back(true);
	}
	//�˰��� ����
	for (int i = 0; i < N; i++) {
		int mins = 1001,mi = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (!arrbool[j]) //�̹� ���� ���ڶ��
				continue; //�Ѿ��.
			if (mins > arr[j]) { //min ���� �������
				mi = j;
				mins = arr[j];
			}
		}
		arrbool[mi] = false;
		outs.push_back(sums + arr[mi]);
		sums += arr[mi];
	}
	sums = 0;
	for (int i = 0; i < outs.size(); i++)
		sums += outs[i];
	cout << sums << "\n"; 
}