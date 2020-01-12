#include <iostream>
#include <queue>
using namespace std;

//[소수 경로](https://www.acmicpc.net/problem/1963)

bool sosu[10000]; //소수인지 미리 저장해두기 위한 변수
int zisu[4] = { 1000,100,10,1 }; //10의 지수를 모아둠.

int N, M;

typedef struct sc { //카운트와 숫자를 저장하기 위한 구조체
	int score;
	int counts;
}S;

//한글자만 바뀌는지 확인하는 함수
bool isOneChange(int n, int m) {
	int tmp1 = n, tmp2 = m;
	for(int i = 0 ; i < 4; i++){
		if (abs(tmp1 - tmp2) % zisu[i] == 0) //앞자리 빼고 나머지가 같다면 트루
			return true;
		else if (tmp1 / zisu[i] != tmp2 / zisu[i]) //앞자리가 다르다면 false
			return false;
		tmp1 %= zisu[i];
		tmp2 %= zisu[i];
	}
}

//실제 문제를 해결하는 함수
void run() {
	bool checks[10000] = { false , }; //들렀는지 안들렀는지 확인하는 변수
	cin >> N >> M;
	queue<S> q;
	S tt = { N, 0 };
	q.push(tt);
	checks[N] = true;
	while (q.front().score != M) { //같은 숫자가 나오면 종료
		S temp = q.front();
		q.pop();
		for (int i = 1001; i < 9999; i++) {
			if (!sosu[i] || checks[i]) continue;
			if (isOneChange(temp.score, i)) { //한자리만 바꾼거라면
				checks[i] = true;
				S tmp = { i,temp.counts + 1 };
				q.push(tmp);
			}
		}
		if (q.empty()) { //비었다면 더이상 돌게 없다는 뜻.
			cout << "Impossible" << "\n";
			return;
		}
	}
	cout << q.front().counts << "\n";
}

//1~9999까지의 소수를 미리 계산해두는 함수
void checkSosu() {
	int counts;
	sosu[1] = true;
	sosu[2] = true;
	for (int i = 3; i < 10000; i++) {
		counts = 0;
		for (int j = 1; j <= i; j++)
			if (i%j == 0)
				counts++;
		if (counts <= 2)
			sosu[i] = true;
	}
}

int main() {
	int tmp;
	cin >> tmp;
	checkSosu();
	for (int i = 0; i < tmp; i++)
		run();
}