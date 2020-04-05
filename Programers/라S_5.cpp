#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

bool compares(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//dataSource배열 크기 최대 100000 * 100000
//tags 최대 크기 10000
vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
	vector<pair<string,int>> tempSave;
	vector<string> answer;
	vector<string> ::iterator iter;
	//하나씩 접근 한다.
	for (int i = 0; i < dataSource.size(); i++) {
		int countsTag = 0;
		for (int j = 0; j < tags.size(); j++) {
			iter = find(dataSource[i].begin(), dataSource[i].end(), tags[j]);
			if (iter != dataSource[i].end())
				countsTag++;
		}
		if(countsTag > 0)
			tempSave.push_back(make_pair(dataSource[i][0], countsTag));
	}
	//사전식 순서로 정렬한다,
	sort(tempSave.begin(), tempSave.end(), compares);
	for (int i = 0; i < 10; i++) {
		if(tempSave.size() > i)
			answer.push_back(tempSave[i].first);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<string>> arr;
	vector<string> tmp;
	tmp.push_back("doc1");
	tmp.push_back("t1");
	tmp.push_back("t2");
	tmp.push_back("t3");
	arr.push_back(tmp);
	tmp[0] = "doc2";
	tmp[1] = "t0";
	tmp[2] = "t2";
	tmp[3] = "t3";
	arr.push_back(tmp);
	tmp[0] = "doc3";
	tmp[1] = "t1";
	tmp[2] = "t6";
	tmp[3] = "t7";
	arr.push_back(tmp);
	tmp[0] = "doc5";
	tmp[1] = "t1";
	tmp[2] = "t2";
	tmp[3] = "t4";
	arr.push_back(tmp);
	tmp[0] = "doc4";
	tmp[1] = "t2";
	tmp[2] = "t1";
	tmp[3] = "t8";
	arr.push_back(tmp);
	vector<string> aa;
	aa.push_back("t1");
	aa.push_back("t2");
	aa.push_back("t3");
	solution(arr,aa);
}