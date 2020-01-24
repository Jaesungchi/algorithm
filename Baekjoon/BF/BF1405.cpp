#include <iostream>
using namespace std;

//[미친 로봇 난이도★★](https://www.acmicpc.net/problem/1405)

int N;//횟수
long double prob[4];
bool map[31][31];
long double result = 0;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void run(int y, int x, int counts,long double p) {
	if (map[y][x]) return; // 이미 갔던곳
	if (counts == N) {
		result += p; //확률
		return; 
	}
	map[y][x] = true;
	for (int i = 0; i < 4; i++)
		run(y + dy[i], x + dx[i], counts + 1, p * prob[i]);
	map[y][x] = false;
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		prob[i] = tmp * 0.01;
	}
	run(15, 15, 0, 1);
	cout.precision(11);
	cout << result << "\n";
}