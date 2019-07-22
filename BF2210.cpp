#include <iostream>
#include <string>
#include <set>
using namespace std;

//https://www.acmicpc.net/problem/2210 숫자판 점프
//중복이 안생길 수도 있어서 string 배열을 999999 사이즈로 만들었더니 메모리 차지가 너무 심함
//그래서 찾아낸 방법이 set함수를 이용하면 알아서 중복을 제거해줌.
//중복 검사할 필요도 없고 딱 좋다.

set<string> m_data;
int map[5][5];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void dfs(int y, int x, string data,int count) {
	if (x < 0 || x >= 5 || y < 0 || y >= 5)
		return;
	if (count == 6) {
		m_data.insert(data);
		return;
	}
	string m_data = data + std::to_string(map[y][x]);
	for (int i = 0; i < 4; i++)
		dfs(y + dy[i], x + dx[i], m_data, count + 1);
}


int main() {
	for(int i = 0 ; i < 5 ; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	for (int i = 0; i < 5; i++)
		for(int j = 0 ; j < 5; j++)
			dfs(i, j, "", 0);
	cout << m_data.size();
}