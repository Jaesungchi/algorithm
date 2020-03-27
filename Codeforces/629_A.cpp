#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void run() {
	int a, b,output = 0,tmp;
	cin >> a >> b;
	if (a < b) {
		output = b - a;
	}
	else if (a%b != 0) {
		tmp = b * (a / b) + b;
		output = tmp - a;
	}
	cout << output << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--)
		run();
}
