#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

vector<vector<string>> goodIds;
set<set<string>> goodSet;
bool **boolCheck;

//ID를 비교해서 가능한경우 True 반환
bool checkID(string id, string ban) {
	if (id.size() != ban.size())
		return false;
	for (int i = 0; i < ban.length(); i++) {
		if (ban[i] == '*')
			continue;
		if (ban[i] != id[i])
			return false;
	}
	return true;
}

void Run(int mSize, int end, vector<string> s) {
	if (mSize == end) { //end 길이까지 가면
		set<string> tmp;
		for (int i = 0; i < s.size(); i++)
			tmp.insert(s[i]);
		if (tmp.size() != end) //아무것도 없다.
			return;
		goodSet.insert(tmp);
		return;
	}
	for (int i = 0; i < goodIds[mSize].size(); i++) {
		if (boolCheck[mSize][i])
			continue;
		boolCheck[mSize][i] = true;
		s.push_back(goodIds[mSize][i]);
		Run(mSize + 1, end, s);
		s.pop_back();
		boolCheck[mSize][i] = false;
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int maxs = 0;
	for (int i = 0; i < banned_id.size(); i++) { //밴 아이디 검색
		vector<string> tmps;
		for (int j = 0; j < user_id.size(); j++) {
			if (checkID(user_id[j], banned_id[i]))
				tmps.push_back(user_id[j]);//비교 한값 푸쉬
		}
		goodIds.push_back(tmps); //한 아이디 비교 푸쉬.
	}
	for (int i = 0; i < goodIds.size(); i++)
		if (maxs < goodIds[i].size())
			maxs = goodIds[i].size();
	//bool 배열 제작
	boolCheck = new bool*[goodIds.size()];
	for (int i = 0; i < goodIds.size(); i++) {
		boolCheck[i] = new bool[maxs];
		fill_n(boolCheck[i], maxs, false);
	}
	vector<string> s;
	Run(0, goodIds.size(), s); //DFS
	return goodSet.size();
}