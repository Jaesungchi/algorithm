#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, counts = 0;
vector<int> a;
vector<int> b;
vector<vector<int>> maps;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0 || i == 0)
			a.push_back(tmp);
		else
			a.push_back(a[i-1] + 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (tmp == 0 || i == 0)
			b.push_back(tmp);
		else
			b.push_back(b[i-1] + 1);
	}
	for (int i = 0; i < n; i++) {
		vector<int> inputs;
		for (int j = 0; j < m; j++) {
			inputs.push_back(a[i] * b[j]);
		}
		maps.push_back(inputs);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] / (i+1) >= k)
				counts++;
			if (maps[i][j] >= k)
				counts++;
			cout << maps[i][j] << " ";
 		}
		cout << "\n";
	}

	cout << counts << "\n";
}