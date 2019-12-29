#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/9012 //°ýÈ£

int n;
string temp1;
char stack[51];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp1;
		int points = -1;
		bool checkOK = true;
		for (int j = 0; j < temp1.size(); j++) {
			if (temp1[j] == '(') {
				points++;
				stack[points] = '(';
			}
			else if (temp1[j] == ')') {
				if (points == -1) {
					checkOK = false;
					break;
				}
				points--;
			}
		}
		if (points != -1) {
			checkOK = false;
		}
		if (checkOK)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}