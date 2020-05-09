#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ll long long

long long answer = 0;
char oper[4] = { ' ','+','-','*' };
int weight[3] = { 0,0,0 };
vector<ll> datas;
vector<char> opers;

//완전 간단한 계산용.
ll operCalcul(char toper, ll a, ll b) {
	ll result = a;
	switch (toper) {
	case '+':
		result += b;
		break;
	case '-':
		result -= b;
		break;
	case '*':
		result *= b;
		break;
	}
	return result;
}

//계산을 한다.
ll calcul() {
	vector<ll> tDatas;
	tDatas.assign(datas.begin(), datas.end());
	vector<char> tOpers;
	tOpers.assign(opers.begin(), opers.end());
	//연산자 종류만큼 시행한다.
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < tOpers.size(); i++) {
			if (tOpers[i] != oper[weight[j]])
				continue;
			tDatas[i] = operCalcul(tOpers[i], tDatas[i], tDatas[i + 1]);
			tDatas.erase(tDatas.begin() + i + 1);
			tOpers.erase(tOpers.begin() + i);
			i--; //지워지면 인덱스를 한칸 땡긴다.
		}
	}
	return abs(tDatas[0]);
}

//우선순위를 종류별로 준다.
void DFS(int idx) {
	if (idx >= 3) {
		answer = max(calcul(), answer);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		bool chk = false;
		for (int j = idx - 1; j >= 0; j--) {
			if (i == weight[j]) {
				chk = true;
				break;
			}
		}
		if (chk)
			continue;
		weight[idx] = i;
		DFS(idx + 1);
		weight[idx] = 0;
	}
}

//글자와 연산자 구분.
void seperate(string exp) {
	string numbers = "";
	for (int i = 0; i < exp.length(); i++) {
		switch (exp[i]) {
		case '-':
			datas.push_back(atoi(numbers.c_str()));
			numbers = "";
			opers.push_back(exp[i]);
			break;
		case '+':
			datas.push_back(atoi(numbers.c_str()));
			numbers = "";
			opers.push_back(exp[i]);
			break;
		case '*':
			datas.push_back(atoi(numbers.c_str()));
			numbers = "";
			opers.push_back(exp[i]);
			break;
		default: //숫자
			numbers += exp[i];
			break;
		}
	}
	datas.push_back(atoi(numbers.c_str()));
}

ll solution(string expression) {
	seperate(expression);
	DFS(0);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution("50*6-3*2");
}