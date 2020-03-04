#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,p,tmp;
	cin >> n >> m >> p;
	vector<int> A;
	vector<int> B;
	vector<int> outs;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		tmp %= p;
		for (int j = 0; j < m; j++) {
			int sum = (A[j] % p) * tmp;
			if (outs.size() < i + j + 1)
				outs.push_back(sum);
			else
				outs[i + j] += sum;
			outs[i + j] %= p;
		}
		if (outs[i] != 0) {
			cout << i << "\n";
			return 0;
		}
	}
}