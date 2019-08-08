#include <iostream>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10026 적녹색약
//오랜만에 DFS푸니깐 재밌당

int n, Acounts = 0,Bcounts = 0 , dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
char datas[101][101];
bool temp1[101][101], temp2[101][101];

void BFS(int x, int y, char check) {
	if (temp1[y][x]) //이미 들른곳이면 리턴
		return;
	temp1[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (datas[y + dy[i]][x + dx[i]] == check)
			if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0)
				BFS(x + dx[i], y + dy[i], check);
	}
}

void BFS2(int x, int y, char check) {
	if (temp2[y][x]) //이미 들른곳이면 리턴
		return;
	temp2[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (check == 'R' || check == 'G') {
			if (datas[y + dy[i]][x + dx[i]] == 'R' || datas[y + dy[i]][x + dx[i]] == 'G')
				if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0)
					BFS2(x + dx[i], y + dy[i], check);
		}
		else {
			if (datas[y + dy[i]][x + dx[i]] == check)
				if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0)
					BFS2(x + dx[i], y + dy[i], check);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> datas[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!temp1[i][j]) {
				BFS(j, i, datas[i][j]);
				Acounts++;
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!temp2[i][j]) {
				BFS2(j, i, datas[i][j]);
				Bcounts++;
			}

	cout << Acounts << " " << Bcounts << "\n";
}