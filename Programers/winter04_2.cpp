#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	answer.assign(k + 1, 0);
	vector<long long> answer2;
	int pos = 0;
	for (auto tmp : room_number) {
		if (answer[tmp] == 0) {
			answer[tmp] = tmp;
			answer2.push_back(tmp);
		}
		else {
			pos = tmp + 1;
			while (answer[pos] != 0) {
				pos++;
			}
			answer[pos] = pos;
			answer2.push_back(pos);
		}
	}

	return answer2;
}

int main() {
	vector<long long> inputs = { 1,10000000,23923,438,3469,40346,433,32495,438 };
	inputs = solution(10, inputs);
	for (int i = 0; i < inputs.size(); i++) {
		cout << inputs[i] << " ";
	}
}