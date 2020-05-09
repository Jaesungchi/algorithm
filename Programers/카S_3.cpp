#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> tgem;
vector<string> arr;

bool isGood(int size, int idx) {
	set<string> chk;
	for (int i = 0; i < size; i++)
		chk.insert(arr[idx + i]);
	if (chk.size() == tgem.size())
		return true;
	else
		return false;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	arr.assign(gems.begin(), gems.end());
	set<string>::iterator iter;
	for (int i = 0; i < gems.size(); i++)
		tgem.insert(gems[i]);
	if (gems.size() == tgem.size()) {
		answer.push_back(1);
		answer.push_back(gems.size());
		return answer;
	}
	int cnt = tgem.size(); //총 갯수.
	if (tgem.size() > gems.size() / 2) { //낮은수에 가까우면.
		while (true) {
			bool chk = false;
			for (int i = 0; i <= gems.size() - cnt; i++) {
				if (isGood(cnt, i)) {
					answer.push_back(i + 1);
					answer.push_back(i + cnt);
					return answer;
				}
			}
			cnt++;
		}
	}
	else { //큰수에 가까우면 gems -1부터 시작.
		cnt = gems.size();
		while (true) {
			bool chk = false;
			for (int i = 0; i <= gems.size() - cnt; i++) {
				if (isGood(cnt, i)) {
					answer.clear();
					answer.push_back(i + 1);
					answer.push_back(i + cnt);
					chk = true;
					break;
				}
			}
			if (!chk)
				break;
			cnt--;
		}
		return answer;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> vi;
	//vi.push_back("DIA");
	//vi.push_back("RUBY");
	//vi.push_back("RUBY");
	//vi.push_back("DIA");
	//vi.push_back("DIA");
	//vi.push_back("EMERALD");
	//vi.push_back("SAPPHIRE");
	//vi.push_back("DIA");
	vi.push_back("ZZZ");
	vi.push_back("YYY");
	vi.push_back("NNNN");
	vi.push_back("YYY");
	vi.push_back("BBB");
	solution(vi);
}