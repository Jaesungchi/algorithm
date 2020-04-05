#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

int maxN = 0;
int answer = 0;

void DFS(string roads,int now, int counts) {
	if (now >= roads.length()) {
		int counts = 0;
		for (int i = 0; i < roads.length(); i++) {
			if (roads[i] == '1')
				counts++;
			else {
				answer = answer > counts ? answer : counts;
				counts = 0;
			}
		}
		answer = answer > counts ? answer : counts;
		cout << roads << "\n";
		return;
	}
	if (roads[now] == '0' && counts < maxN) {
		roads[now] = '1';
		DFS(roads, now + 1, counts + 1);
		roads[now] = '0';
	}
	DFS(roads, now + 1, counts);

}

int solution(string road, int n) {
	maxN = n;
	DFS(road, 0, 0);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string road;
	int n;
	cin >> road;
	cin >> n;
	cout << solution(road,n);
}