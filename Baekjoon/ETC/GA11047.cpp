#include <iostream>
#include <vector>
using namespace std;

//�׸��� �˰���
//https://www.acmicpc.net/problem/11047 ���� 0

int main() {
	int N, M,tmp,count = 0 , i;
	vector<int> money;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		money.push_back(tmp);
	}
	for (i = money.size() - 1; i >= 0; i--) {
		if (M == 0)
			break;
		int tCount = M / money[i];
		count += tCount;
		M -= money[i] * tCount;
		
	}
	cout << count;
}