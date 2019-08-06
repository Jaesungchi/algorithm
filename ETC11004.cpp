#include <iostream>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/11004 K¹øÂ° ¼ö

int n,k;
int datas[5000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> datas[i];
	sort(datas, datas + n);
	cout << datas[k-1];
}