#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

bool compare(vector<string> a, vector<string> b) {
	return a[0] < b[0];
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
	vector<string> already;
	vector<string> ::iterator iter;
	for (int i = 0; i < transactions.size(); i++) {
		string id = transactions[i][0];
		string fun = transactions[i][1];
		string user = transactions[i][2];
		vector<string> newData;
		int much = atoi(transactions[i][3].c_str());
		//이미 돌아본 id인지 확인
		iter = find(already.begin(), already.end(), id);
		if (already.size() > 0 && iter == already.end())
			continue;
		already.push_back(id);
		bool haveAccount = false;
		//command 해결
		switch (fun[0]) {
		case 'S':
			for (int j = 0; j < snapshots.size(); j++) {
				if (snapshots[j][0].compare(user))
					continue;
				much += atoi(snapshots[j][1].c_str());
				snapshots[j][1] = to_string(much);
				haveAccount = true;
				break;
			}
			if (!haveAccount) {
				newData.push_back(user);
				newData.push_back(to_string(much));
				snapshots.push_back(newData);
			}
			break;
		case 'W':
			for (int j = 0; j < snapshots.size(); j++) {
				if (snapshots[j][0].compare(user))
					continue;
				much = atoi(snapshots[j][1].c_str()) - much;
				snapshots[j][1] = to_string(much);
				haveAccount = true;
				break;
			}
			if (!haveAccount) {
				newData.push_back(user);
				newData.push_back(to_string(much));
				snapshots.push_back(newData);
			}
			break;
		}
	}
	sort(snapshots.begin(), snapshots.end(),compare);
	return snapshots;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<string>> aa;
	vector<vector<string>> bb;
	vector<string> tmp;
	tmp.push_back("account1");
	tmp.push_back("100");
	aa.push_back(tmp);
	tmp[0] = "account2";
	tmp[1] = "150";
	aa.push_back(tmp);
	tmp[0] = "1";
	tmp[1] = "SAVE";
	tmp.push_back("account2");
	tmp.push_back("100");
	bb.push_back(tmp);
	tmp[0] = "2";
	tmp[1] = "WITHDRAW";
	tmp[2] = "account1";
	tmp[3] = "50";
	bb.push_back(tmp);
	tmp[0] = "1";
	tmp[1] = "SAVE";
	tmp[2] = "account2";
	tmp[3] = "100";
	bb.push_back(tmp);
	tmp[0] = "4";
	tmp[1] = "SAVE";
	tmp[2] = "account3";
	tmp[3] = "500";
	bb.push_back(tmp);
	tmp[0] = "3";
	tmp[1] = "WITHDRAW";
	tmp[2] = "account2";
	tmp[3] = "30";
	bb.push_back(tmp);
	solution(aa, bb);
}