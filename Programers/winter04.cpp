#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long maxs = room_number[0],mins = room_number[0]; //���� ��û���� ���� ū,���� ������
	answer.push_back(maxs);
	for (int i = 1; i < room_number.size(); i++) {//�迭�� ���鼭 Ȯ��
		long long inputs = room_number[i];
		if (maxs < inputs) { //�ִ밪���� ũ�� �ٷ� �ְ� �Ѿ.
			answer.push_back(inputs);
			maxs = inputs;
			continue;
		}
		if (mins > inputs) { //�ּҰ����� ������ �ٷ� �ְ� �Ѿ.
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