#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<int> tmp;
	long long counts = 1;
	for (int i = 1; i <= n; i++) {
		counts *= i;
		tmp.push_back(i);
	}
	// /로 나눠서 위치를 직접 찾아간다.
	while (n > 0) {
		long long cut = counts / n;
		int now = (k - 1) / cut;
		answer.push_back(tmp.at(now));
		tmp.erase(tmp.begin() + now);
		k = k % cut;
		if (k == 0)
			k = cut;
		counts = cut;
		n--;
	}
	return answer;
}

int main() {
	solution(3, 5);
}