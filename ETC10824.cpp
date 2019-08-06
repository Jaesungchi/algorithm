#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10824 ³× ¼ö

long long int A, B, C, D;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C >> D;
	for (int i = 1; i < 8; i++){
		int temp1 = 10;
		for (int j = 1; j < i; j++)
			temp1 *= 10;
		if (B < temp1 && B >= temp1 / 10) {
			A *= temp1;
			A += B;
		}
		if (D < temp1 && D >= temp1 / 10) {
			C *= temp1;
			C += D;
		}
	}

	cout << A+C << "\n";

}