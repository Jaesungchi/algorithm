#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// b의 최대는 n(n-1) / 2 이다.

void run() {
	int a, b, i,tmp;
	cin >> a >> b;
	for (i = a; i > 1 ; i--) {
		tmp = (i*(i - 1)) / 2;
		if (tmp < b)
			break;
	}
	//i ~ i-1 의 사이에 있다. ex i == 5 면 baaab ~ bbaaa 7 ~ 10 사이.
	string output = "b";
	for (int j = 0; j < i; j++)
		output += "a";
	i++;
	output[(i*(i - 1) / 2) - b+1] = 'b';
	for (i = output.length(); i < a; i++)
		cout << "a";
	cout << output << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--)
		run();
}