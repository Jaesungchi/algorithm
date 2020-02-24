#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//[624_A](https://codeforces.com/contest/1311/problem/A)

//홀수는 더할수 있고
//짝수는 뺄 수 있다.

void run() {
	int counts = 0;
	int a, b;
	cin >> a >> b;
	while (a != b) {
		if (a < b) { //a가 작음 홀수를 더해야함
			if ((b - a) % 2 == 1) { //차이가 홀수면 바로 끝남
				counts++;
				break;
			}
			else {
				a += (b - a) - 1;
				counts++;
			}
		}
		else { //짝수를 빼야함.
			if ((a - b) % 2 == 0) { //차이가 홀수면 바로 끝남
				counts++;
				break;
			}
			else {
				a -= (a - b) + 1;
				counts++;
			}
		}
	}
	cout << counts << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
		run();
}