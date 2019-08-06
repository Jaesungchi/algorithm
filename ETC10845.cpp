#include <iostream>
#include <queue>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10845 ť

string temp;
int n,temp1;
queue <int> datas;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "push") {
			cin >> temp1;
			datas.push(temp1);
		}
		else if (temp == "front") {
			if (datas.size() != 0)
				cout << datas.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (temp == "back") {
			if (datas.size() != 0)
				cout << datas.back() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (temp == "empty") {
			if (datas.size() != 0)
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
		else if (temp == "size") {
			cout << datas.size() << "\n";
		}
		else if (temp == "pop") {
			if (datas.size() != 0) {
				cout << datas.front() << "\n";
				datas.pop();
			}
			else
				cout << -1 << "\n";
		}

	}
}