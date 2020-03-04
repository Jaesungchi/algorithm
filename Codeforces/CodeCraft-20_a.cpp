#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void run() {
	// a = number of Student;
	// b = highest Score;
	int a, b, tmp, myScore;
	long long int sum = 0;
	cin >> a >> b;
	cin >> myScore;
	sum += myScore;
	for (int i = 1; i < a; i++) {
		cin >> tmp;
		sum += tmp;
		if (myScore + tmp <= b) //최대값보다 작다면 그 값을 더해본다.
			myScore += tmp;
		else if (myScore < b)
			myScore = b;
	}
	cout << myScore << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--)
		run();
}