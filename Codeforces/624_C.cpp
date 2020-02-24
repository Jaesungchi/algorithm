#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//[624_C](https://codeforces.com/contest/1311/problem/C)

void run() {
	int n, m, maxs = 0;
	int mArr[200001];
	int sums[27] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int counts[27] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
		cin >> mArr[i];
	sort(mArr, mArr + m); //정렬해서 작은값부터 더해나감.
	for (int i = 0; i < m; i++) {
		for (int j = maxs; j < mArr[i]; j++)
			sums[s[j] - 'a']++;
		maxs = mArr[i];
		for (int j = 0; j < 26; j++)
			counts[j] += sums[j];
	}
	for (int j = 0; j < 26; j++)
		counts[j] += sums[j];
	for (int i = maxs; i < s.length(); i++)
		counts[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << counts[i] << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
		run();
}