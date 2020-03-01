#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<int> outputs;
	outputs.push_back(triangle[0][0]);
	for (int i = 1; i < triangle.size(); i++) {
		vector<int> tmpOut;
		//제일 왼쪽은 왼쪽을 더함
		tmpOut.push_back(outputs[0] + triangle[i][0]);
		//가운데는 가운데 둘중 
		for (int j = 1; j < i; j++) {
			int goods = outputs[j] > outputs[j - 1] ? outputs[j] : outputs[j - 1];
			tmpOut.push_back(goods + triangle[i][j]);
		}
		//제일 오른쪽에 추가.
		tmpOut.push_back(outputs[i - 1] + triangle[i][i]);
		outputs = tmpOut;
	}
	for (int i = 0; i < outputs.size(); i++)
		if (outputs[i] > answer)
			answer = outputs[i];
	return answer;
}
/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/

int main() {
	vector<vector<int>> inputs;
	vector<int> tmp;
	tmp.push_back(7);
	inputs.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(8);
	inputs.push_back(tmp);
	tmp.clear();
	tmp.push_back(8);
	tmp.push_back(1);
	tmp.push_back(0);
	inputs.push_back(tmp);
	tmp.clear();
	tmp.push_back(2);
	tmp.push_back(7);
	tmp.push_back(4);
	tmp.push_back(4);
	inputs.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(5);
	tmp.push_back(2);
	tmp.push_back(6);
	tmp.push_back(5);	
	inputs.push_back(tmp);
	cout << solution(inputs);
}