/* //10403 간단함...
#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C << "\n";
	cout << (A%C + B%C) % C << "\n";
	cout << (A * B) % C << "\n";
	cout << (A%C * B%C) % C << "\n";
}
*/
/* //2609 최대공약수 최소공배수
#include <iostream>
using namespace std;

int main() {
	int A, B,temp;
	cin >> A >> B;
	if (A < B) {
		temp = A;
		A = B;
		B = temp;
	}
	for (int i = B; i >= 1; i--)
		if (B%i == 0 && A%i == 0) {
			cout << i << "\n";
			break;
		}
	for (int i = A; i <= A * B; i++)
		if (i%A == 0 && i%B == 0) {
			cout << i << "\n";
			break;
		}
}
*/
/* //1978 소수구하기
#include <iostream>
using namespace std;

int main() {
	int N, temp, counts = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		int tt = 0;
		for (int j = temp; j >= 1; j--)
			if (temp % j == 0)
				tt++;
		if (tt == 2)
			counts++;
	}
	cout << counts;
}
*/
