#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

//[단어 수학 난이도★★★](https://www.acmicpc.net/problem/1339)

int N;
int alphabet[26];
string s;
int ans = 0;
vector<int> vec;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			alphabet[s[j] - 65] += (int)pow(10, s.length() - j - 1);
	}

	for (int i = 0; i < 26; i++)
		if (alphabet[i])
			vec.push_back(alphabet[i]);

	int cnt = 9;
	sort(vec.begin(), vec.end(), desc);
	for (int i = 0; i < vec.size(); i++)
		ans += vec[i] * (cnt--);

	cout << ans << endl;
}