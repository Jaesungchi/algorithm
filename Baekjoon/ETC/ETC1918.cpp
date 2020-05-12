#include <iostream>
#include <string>
#include <stack>
using namespace std;

//[후위 표기식 난이도★](https://www.acmicpc.net/problem/1918)

string datas,output;
stack<char> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> datas;
	for (int i = 0; i < datas.length(); i++) {
		switch (datas[i]) {
		case '(':
			s.push(datas[i]);
			break;
		case ')':
			while (!s.empty() && s.top() != '(') {
				output += s.top();
				s.pop();
			}
			s.pop(); //(를 뺀다.
			break;
		case '*':
		case '/': //우선순위가 같은애들을 출력한다.
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				output += s.top();
				s.pop();
			}
			s.push(datas[i]);
			break;
		case '+':
		case '-'://우선순위 빠른애들을 뽑는다.
			while (!s.empty() && s.top() != '(') {
				output += s.top();
				s.pop();
			}
			s.push(datas[i]);
			break;
		default:
			output += datas[i];
			break;
		}
	}
	while (!s.empty()) {
		output += s.top();
		s.pop();
	}
	cout << output << "\n";
}