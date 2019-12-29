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
		answer.push_back(0); //반을 접기 때문에 0 추가
		for (int i = answer.size() - 2; i >= 0; i--) //그 전의 역수를 반대로 넣는다.
			if (answer[i] == 0) //0 이면 1
				answer.push_back(1);
			else //1 이면 0
				answer.push_back(0);
	}
	prints(answer);
}