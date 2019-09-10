#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/16360 //Go Latin
//ICPC 吝 力老 浆款 巩力

int main() {
	int N;
	string datas;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> datas;
		char temp = datas[datas.length()-1];
		if(temp == 'a' || temp == 'o' || temp == 'u')
			cout << datas << "s";
		else if (temp == 'i' || temp == 'y') {
			for (int z = 0; z < datas.length() - 1; z++)
				cout << datas[z];
			cout << "ios";
		}
		else if (temp == 'l' || temp == 'r' || temp == 'v')
			cout << datas << "es";
		else if (temp == 't' || temp == 'w')
			cout << datas << "as";
		else if (temp == 'n') {
			for (int z = 0; z < datas.length() - 1; z++)
				cout << datas[z];
			cout << "anes";
		}
		else if (temp == 'e') {
			if (datas[datas.length() - 2] == 'n') {
				for (int z = 0; z < datas.length() - 2; z++)
					cout << datas[z];
				cout << "anes";
			}
			else
				cout << datas << "us";
		}
		else {
			cout << datas << "us";
		}
		cout << "\n";
	}
}