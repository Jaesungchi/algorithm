#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//[추월 난이도★★](https://www.acmicpc.net/problem/2002)

int n;
queue<string> starts,finish;
vector<string> pass;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int counts = 0;
	string tmp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		starts.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		finish.push(tmp);
	}
	while(!finish.empty()) {
		bool flag = false;
		string a = starts.front();
		string b = finish.front();
		if (a == b) {
			starts.pop();
			finish.pop();
			continue;
		}
		//pass 목록에 있는지 확인한다.
		for (int i = 0; i < pass.size(); i++)
			if (a == pass[i]) {
				starts.pop();
				flag = true;
				break;
			}
		if(!flag){
			pass.push_back(b);
			finish.pop();
			counts++;
		}
	}
	cout << counts << "\n";
}