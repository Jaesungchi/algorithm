#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long maxs = room_number[0],mins = room_number[0]; //현재 신청자중 제일 큰,작은 사이즈
	answer.push_back(maxs);
	for (int i = 1; i < room_number.size(); i++) {//배열을 돌면서 확인
		long long inputs = room_number[i];
		if (maxs < inputs) { //최대값보다 크면 바로 넣고 넘어감.
			answer.push_back(inputs);
			maxs = inputs;
			continue;
		}
		if (mins > inputs) { //최소값보다 작으면 바로 넣고 넘어감.
			answer.push_back(inputs);
			mins = inputs;
			continue;
		}
		while (true) {
			bool flag = false;
			for (int j = 0; j < answer.size(); j++)
				if (inputs == answer[j]) {
					inputs++;
					flag = true;
					break;
				}
			if (flag == false)
				break;
		}
		answer.push_back(inputs);
	}
	return answer;
}

int main() {
	vector<long long> inputs = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	inputs = solution(20, inputs);
	for (int i = 0; i < inputs.size(); i++) {
		cout << inputs[i] << " ";
	}
}