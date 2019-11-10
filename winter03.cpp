#include <string>
#include <vector>

using namespace std;

//ID를 비교해서 가능한경우 True 반환
bool checkID(string id, string ban) {
	if (id.length() != ban.length())
		return false;
	for (int i = 0; i < ban.length; i++) {
		if (ban[i] == '*')
			continue;
		if (ban[i] != id[i])
			return false;
	}
	return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	vector<vector<bool>> arrs;
	for (int i = 0; i < banned_id.size(); i++) { //밴 아이디 검색
		vector<bool> boolcheck;
		for (int j = 0; j < user_id.size(); j++) {
			boolcheck.push_back(checkID(user_id[j], banned_id[i])); //비교 한값 푸쉬
		}
		arrs.push_back(boolcheck); //한 아이디 비교 푸쉬.
	}
	//만들어진 배열을 토대로 같은 bool 이 아닌것 만 더함
	int counts = 0;
	for (int i = 0; i < banned_id.size()-1; i++) {
		bool flag = true;
		for (int j = i+1; j < banned_id.size(); j++) {
			if (banned_id[i] == banned_id[j])
				counts++;
		}
	}

	return answer;
}

int main() {


}