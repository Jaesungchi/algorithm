#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//[LCS](https://www.acmicpc.net/problem/9251)

int dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a;
	cin >> b;
	//이 위까지는 기본 세팅
	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++)
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	cout << dp[a.length()][b.length()] << "\n";
}