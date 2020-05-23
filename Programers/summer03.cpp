#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> result;

int isOK(vector<int> arr,vector<int> child, int data) {
	result.clear();
	vector<int> score(arr.size(),0);
	vector<bool> chk(arr.size(), false);
	queue<int> q;
	int sum = 0;
	for (int i = 0; i < child.size(); i++) { //자식없는 자식들의 score추가.
		score[child[i]] = data;
		q.push(child[i]);
	}
	while (!q.empty()) { 
		int tmp = q.front();
		q.pop();
		if (arr[tmp] == 0 || chk[tmp])// 이미 한번 들렸던 자식이거나 부모가 없다면 넘어감
			continue;
		score[arr[tmp]] += score[tmp];
		chk[tmp] = true;
		q.push(arr[tmp]);
	}
	for (int i = 1; i < score.size(); i++) {
		result.push_back(score[i]);
		sum += score[i];
	}
	return sum;
}

vector<int> solution(int a, vector<vector<int>> skills) {
	vector<int> arr(skills.size()+2);
	vector<bool> child(skills.size()+2,true); //자식들만 찾기위한 벡터
	for (int i = 0; i < skills.size(); i++) {
		arr[skills[i][1]] = skills[i][0]; //트리처럼 만드는데 거꾸로 자식이 부모위치를 알고 부모는 자식을 모른다.
		child[skills[i][0]] = false;
	}
	vector<int> sunhangIndex; //자식 인덱스 저장위한 벡터
	for (int i = 1; i < arr.size(); i++)
		if (child[i]) //자식이 없는 자식이라면
			sunhangIndex.push_back(i);

	//자식이 없는 애들 index을 sunhangIndex에 갖고 있음.
	//모든 자식없는 애들 값이 똑같음. 그래서 갖고 있는다.

	int left = 0, right = a / 2; //반을 넘어갈 일이 없음. 사실 넘어갈수도 있으니 그냥 a로 해도됨.

	while (left <= right) {
		int mid = (left + right) / 2;
		int sumdata = mid / sunhangIndex.size();
		int omg = isOK(arr, sunhangIndex, mid);
		if (a == omg)
			break;
		else if (a < omg)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return result;
}

int main() {
	int sp = 121;
	vector<vector<int>> skills;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	skills.push_back(tmp);
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(3);
	skills.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(6);
	skills.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(4);
	skills.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(5);
	skills.push_back(tmp);
	vector<int> output = solution(sp, skills);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
}