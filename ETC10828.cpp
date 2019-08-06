#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10828 ½ºÅÃ

int stack[10001], points = -1, N,temp;
string names;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> names;
		if (names == "push")
			cin >> temp;
		if (names == "push") {
			points++;
			stack[points] = temp;
		}
		else if (names == "top") {
			if (points == -1)
				cout << -1 << "\n";
			else
				cout << stack[points] << "\n";
		}
		else if (names == "size") {
			cout << points + 1 << "\n";
		}
		else if (names == "empty") {
			if (points == -1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (names == "pop") {
			if (points == -1)
				cout << -1 << "\n";
			else {
				cout << stack[points] << "\n";
				points--;
			}
		}
	}
}