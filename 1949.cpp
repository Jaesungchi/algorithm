#include <iostream>
using namespace std;

//삼성 1949 등산로 조성

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 } ,maps[8][8];
int goodSet,d_max,out_max= 0;
bool visited[8][8];

struct checkPoint {
	int y, x, h,count;
	bool chk;
};

bool CheckOutMap(int y, int x) {
	if (y < 0 || y >= d_max || x < 0 || x >= d_max)
		return true;
	return false;
}

void dfs(checkPoint x1) {
	for (int i = 0; i < 4; i++) {
		bool flag = false;
		if (CheckOutMap(x1.y + dy[i], x1.x + dx[i]) || visited[x1.y+dy[i]][x1.x+dx[i]])
			continue;
		checkPoint x2 = { x1.y + dy[i],x1.x + dx[i],maps[x1.y + dy[i]][x1.x + dx[i]] ,x1.count + 1,x1.chk };
		if (x1.h > x2.h)
			flag = true;
		else {
			if (!x1.chk && x1.h > x2.h - goodSet) {
				x2.chk = true;
				x2.h = x1.h - 1;
				flag = true;
			}
		}
		if (flag) {
			if (out_max < x2.count) out_max = x2.count;
			visited[x2.y][x2.x] = true;
			dfs(x2);
			visited[x2.y][x2.x] = false;
		}
	}
}


void StartTest() {
	int tempMax = 0, map[8][8];
	out_max = 0;
	cin >> d_max >> goodSet;
	for (int i = 0; i < d_max; i++)
		for (int j = 0; j < d_max; j++) {
			cin >> map[i][j];
			if (tempMax < map[i][j])
				tempMax = map[i][j];
		}
	for (int i = 0; i < d_max; i++)
		for (int j = 0; j < d_max; j++) {
			if (map[i][j] == tempMax) {
				checkPoint cur = { i,j,map[i][j],1,false };
				visited[i][j] = true;
				dfs(cur);
				visited[i][j] = false;
			}
		}

}

int main() {
	int temp = 0;
	cin >> temp;
	for (int k = 0; k < temp; k++) {
		StartTest();
		cout << "#" << k + 1 << " " << out_max << "\n";
	}
}