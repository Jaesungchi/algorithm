#include <iostream>
#include <string>
#include <stack>
using namespace std;

//https://www.acmicpc.net/problem/10799 //쇠막대기
//규칙 찾기 힘들었음. 생각보다..

string temp1;
int counts = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<char> datas;
	cin >> temp1;
	bool isClose = false;
	for (int i = 0; i < temp1.size(); i++) {
		if (temp1[i] == '(') {
			datas.push('(');
			isClose = true;
		}
		else {
			datas.pop();
			if (isClose)
				counts += datas.size();
			else
				counts += 1;
			isClose = false;
		}
	}
	cout << counts << "\n";
}