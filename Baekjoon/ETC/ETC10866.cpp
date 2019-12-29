#include <iostream>
#include <deque>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10866 µ¦

deque <int> datas;
int n, temp1;
string temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "push_front") {
			cin >> temp1;
			datas.push_front(temp1);
		}
		else if (temp == "push_back") {
			cin >> temp1;
			datas.push_back(temp1);
		}
		else if (temp == "pop_front") {
			if (datas.size() == 0)
				cout << -1 << "\n";
			else {
				cout << datas.front() << "\n";
				datas.pop_front();
			}
		}
		else if (temp == "pop_back") {
			if (datas.size() == 0)
				cout << -1 << "\n";
			else {
				cout << datas.back() << "\n";
				datas.pop_back();
			}
		}
		else if (temp == "size") {
			cout << datas.size() << "\n";
		}
		else if (temp == "empty") {
			if (datas.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (temp == "front") {
			if (datas.size() == 0)
				cout << -1 << "\n";
			else {
				cout << datas.front() << "\n";
			}
		}
		else if (temp == "back") {
			if (datas.size() == 0)
				cout << -1 << "\n";
			else {
				cout << datas.back() << "\n";
			}
		}
	}
}