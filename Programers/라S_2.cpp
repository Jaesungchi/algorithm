#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };


int solution(string answer_sheet, vector<string> sheets) {
	int answer = 0; //부정행위 지수 (의심 문항 + 가장긴 의심 ^2)
	for (int i = 0; i < sheets.size() - 1; i++) {
		for (int j = i + 1; j < sheets.size(); j++) {
			int susCounts = 0; //의심 문항 수
			int maxLength = 0; //가장 긴 의심 문항 수.		
			int beforeSus = 0;
			for (int k = 0; k < sheets[i].length(); k++) {
				if (sheets[i][k] != sheets[j][k]) { //둘이 다르면 넘김
					maxLength = maxLength > beforeSus ? maxLength : beforeSus;
					beforeSus = 0;
					continue;
				}
				if (sheets[i][k] == sheets[j][k] && sheets[i][k] == answer_sheet[k]) {
					maxLength = maxLength > beforeSus ? maxLength : beforeSus;
					beforeSus = 0;
					continue; //둘이 같지만 답이라면 넘김.
				}
				susCounts++;
				beforeSus++;
			}
			maxLength = maxLength > beforeSus ? maxLength : beforeSus;
			int susScore = susCounts + maxLength * maxLength;
			if (answer < susScore)
				answer = susScore;
		}
	}
	return answer;
}

/*
4132315142
3241523133
4121314445
3243523133
4433325251
2412313253
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string tmp,tmp2;
	vector<string> arr;
	cin >> tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp2;
		arr.push_back(tmp2);
	}
	cout << solution(tmp, arr);
}