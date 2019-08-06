#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10808 ¾ËÆÄºª °³¼ö

string datas;
int temps[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> datas;
	for (int i = 0; i < datas.size(); i++) {
		temps[datas[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << temps[i] << " ";
	cout << "\n";
}