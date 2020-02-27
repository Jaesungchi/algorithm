#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//[암호 만들기 난이도★★](https://www.acmicpc.net/problem/1759)

int L, C;
vector<char> alpha;

bool isGood(string datas) {
	int ca = 0, cb = 0;
	for (int i = 0; i < datas.length(); i++) {
		if (datas[i] == 'a' || datas[i] == 'e' || datas[i] == 'o' || datas[i] == 'u' || datas[i] == 'i')
			ca++;
		else
			cb++;
	}
	if (ca < 1 || cb < 2)
		return false;
	return true;
}

void DFS(string datas,int indexAlpha) {
	if (datas.length() >= L) {
		if(isGood(datas))
			cout << datas << "\n";
		return;
	}
	if (indexAlpha >= C)
		return;
	DFS(datas + alpha[indexAlpha], indexAlpha + 1);
	DFS(datas, indexAlpha + 1);	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char inputs;

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> inputs;
		alpha.push_back(inputs);
	}
	sort(alpha.begin(), alpha.end());
	DFS("", 0);
}