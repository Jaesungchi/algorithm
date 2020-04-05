#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };


int solution(string inputString) {
	int answer = 0;
	int one = 0, two = 0, three = 0, four = 0; //() {} [] <>순
	for (int i = 0; i < inputString.length(); i++) {
		switch (inputString[i])
		{
		case '(':
			one++;
			break;
		case ')':
			if (one > 0) {
				answer++;
				one--;
			}
			else
				return -1;
			break;
		case '{':
			two++;
			break;
		case '}':
			if (two > 0) {
				answer++;
				two--;
			}
			else
				return -1;
			break;
		case '[':
			three++;
			break;
		case ']':
			if (three > 0) {
				answer++;
				three--;
			}
			else
				return -1;
			break;
		case '<':
			four++;
			break;
		case '>':
			if (four > 0) {
				answer++;
				four--;
			}
			else
				return -1;
			break;
		default:
			break;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string tmp;
	cin >> tmp;
	cout << solution(tmp);
}