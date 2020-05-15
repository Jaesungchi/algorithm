#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//[과외맨 난이도★★](https://www.acmicpc.net/problem/5213)
/*
	시간을 오래 투자해야하는 문제.
	난이도는 쉽다.
*/

typedef struct Node {
	int number;
	int left, right;
}P;

int N;
int lastNum = 1;
vector<vector<P>> arr;
bool chk[300000];
int before[300000];
int dy[6] = { -1,-1,0,0,1,1 }, dx1[6] = { -1,0,-1,1,-1,0 };
int dx2[6] = { 0,1,-1,1,0,1 };

bool CanGo(int y, int x, int ty, int tx) {
	if (ty < 0 || ty >= N || tx < 0)
		return false;
	if (ty % 2 == 0 && tx >= N)
		return false;
	if (ty % 2 == 1 && tx >= N - 1)
		return false;
	if (y == ty) { //양 옆을 확인.
		if (x < tx && arr[y][x].right == arr[ty][tx].left)//오른쪽
			return true; 
		if (arr[y][x].left == arr[ty][tx].right)
			return true;
		return false;
	}
	//위 아래를 확인.
	if (y % 2 == 0) { //짝수일때.
		if (x == tx) {
			if (arr[y][x].right == arr[ty][tx].left)
				return true;
		}
		else {
			if (arr[y][x].left == arr[ty][tx].right)
				return true;
		}
		return false;
	}
	if (x == tx){
		if(arr[y][x].left == arr[ty][tx].right)
			return true;
	}
	else {
		if (arr[y][x].right == arr[ty][tx].left)
			return true;
	}
	return false;
}

void BFS() {
	queue<pair<int,int>> q;
	vector<int> output;
	output.push_back(1);
	q.push(make_pair(0,0));
	chk[1] = true;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		if (arr[y][x].number == lastNum)
			return ;
		for (int i = 0; i < 6; i++) {
			int tx;
			if (y % 2 == 0)
				tx = x + dx1[i];
			else
				tx = x + dx2[i];
			int ty = y + dy[i];
			if (!CanGo(y, x, ty, tx))
				continue;
			if (chk[arr[ty][tx].number])
				continue;
			chk[arr[ty][tx].number] = true;
			before[arr[ty][tx].number] = arr[y][x].number;
			q.push(make_pair(ty, tx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<P> tmp;
		int limit = i % 2 == 0 ? N : N - 1;
		for (int j = 0; j < limit ; j++) {
			P tnew;
			cin >> tnew.left >> tnew.right;
			tnew.number = lastNum++;
			tmp.push_back(tnew);
		}
		arr.push_back(tmp);
	}
	lastNum--;
	BFS();
	vector<int> road;
	road.push_back(lastNum);
	int bR = before[lastNum];
	while (bR != 1) {
		road.push_back(bR);
		bR = before[bR];
	}
	road.push_back(bR);
	cout << road.size() << "\n";
	for (int i = road.size()-1 ; i >= 0; i--) {
		cout << road[i] << " ";
	}
	return 0;
}