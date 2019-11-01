#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
1
2
3
4
5

0
0 0 1
0 0 1 0 0 1 1
0 0 1 0 0 1 1 0 0 0 1 1 0 1 1

*/

void prints(vector <int> answer) {
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}

int main() {
	int n;
	cin >> n;

	vector<int> answer;
	for (int i = 0; i < n; i++) {
		answer.push_back(0); //���� ���� ������ 0 �߰�
		for (int i = answer.size() - 2; i >= 0; i--) //�� ���� ������ �ݴ�� �ִ´�.
			if (answer[i] == 0) //0 �̸� 1
				answer.push_back(1);
			else //1 �̸� 0
				answer.push_back(0);
	}
	prints(answer);
}