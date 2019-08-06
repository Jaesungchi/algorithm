#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/11655 ROT13

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string datas;
	char datas1;
	getline(cin, datas);
	for (int i = 0; i < datas.length(); i++) {
		if (datas[i] >= 'a'&& datas[i] <= 'z') {
			datas1 = (datas[i] - 'a' + 13) % 26 + 'a';
			cout << datas1;
		}
		else if (datas[i] >= 'A' && datas[i] <= 'Z') {
			datas1 = (datas[i] - 'A' + 13) % 26 + 'A';
			cout << datas1;
		}
		else
			cout << datas[i];
	}
}