#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
8 12
80

2 2
2

3 3
6

2 3
2

4 6
16

2 5
4

3 5   1.88
8
*/
//최대 공약수로 구하고
// 그 비율의 2.5 면 3 칸 3 칸 씩 빠짐

int gcd(int a, int b)
{
	int c;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h)
{
	long long answer = 0, box_size = w * h;
	int gcds = gcd(w, h);

	answer = ceil(box_size - (w + h - gcds));

	return answer;
}


int main() {
	int w, h;
	cin >> w >> h;
	while (w != 0) {
		cout << solution(w, h) << "\n";
		cin >> w >> h;
	}
}