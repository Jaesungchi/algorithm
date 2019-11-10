#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> makeVector(vector<vector<int>> outs) {
	int i, j, k;
	vector<int> answer;
	for (int siz = 1; siz <= outs.size(); siz++) { //순서대로 찾기 위한 변수
		for (i = 0; i < outs.size(); i++) { //순서대로 돌면서 찾는다.
			if (outs[i].size() != siz) continue;
			int findNum = -1, flag = 0;
			for (k = 0; k < outs[i].size(); k++) {
				flag = 0;
				for (j = 0; j < answer.size(); j++) { //사이즈 만큼 없는걸 돌면서 찾는다.
					if (outs[i][k] == answer[j])
						flag = 1;
				}
				if (flag == 0 || siz == 1) {
					findNum = outs[i][k];
					break;
				}
			}
			answer.push_back(findNum);
			break;
		}
	}
	return answer;
}

vector<int> solution(string s) {
	vector<vector<int>> outs;
	vector<string> m_string;
	char str_buff[1000000];
	int i,j,k; //제일 긴 값을 저장하기 위한 변수
	strcpy(str_buff, s.c_str()); //형변환
	char *tmp = strtok(str_buff,"{}");
	while(tmp != NULL){
		if (strcmp(tmp, ",") != 0)//쉼표만 있는게 아니라면
			m_string.push_back(tmp);
		tmp = strtok(NULL, "{}");
	}
	//벡터 배열로 저장. 저장하는 파트
	for (i = 0; i < m_string.size(); i++) {
		vector<int> strings;
		strcpy(str_buff, m_string[i].c_str());
		char *datas = strtok(str_buff, ",");
		while (datas != NULL) {
			strings.push_back(atoi(datas));
			datas = strtok(NULL, ",");
		}
		outs.push_back(strings);
	}
	return makeVector(outs);
}

int main() {
	string input = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> output = solution(input);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
}