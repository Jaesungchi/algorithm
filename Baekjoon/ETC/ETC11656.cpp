#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/11656 접미사 배열

string temp1;

bool sortCheck(string &u, string&v) {
	for (int i = 0; i < u.length(); i++) {
		if (u[i] < v[i]) return true;
		else if (u[i] > v[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> temp1;
	vector <string> datas(temp1.length());
	for (int i = 0; i < temp1.length(); i++)
		datas[i] = temp1.substr(i, temp1.length());

	sort(datas.begin(), datas.end(),sortCheck);

	for (int i = 0; i < temp1.length(); i++)
		cout << datas[i] << "\n";
}