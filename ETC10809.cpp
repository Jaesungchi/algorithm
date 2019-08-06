#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10809 ¾ËÆÄºª Ã£±â

string datas;
int temp[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> datas;

	for (int i = 0; i < datas.size(); i++) {
		if (temp[datas[i] - 'a'] == 0)
			temp[datas[i] - 'a'] = i+1;
	}
	for (int i = 0; i < 26; i++) {
		if (temp[i] == 0)
			cout << -1 << " ";
		else
			cout << temp[i]-1 << " ";
	}
}