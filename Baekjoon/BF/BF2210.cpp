#include <iostream>
#include <string>
#include <set>
using namespace std;

//https://www.acmicpc.net/problem/2210 ������ ����
//�ߺ��� �Ȼ��� ���� �־ string �迭�� 999999 ������� ��������� �޸� ������ �ʹ� ����
//�׷��� ã�Ƴ� ����� set�Լ��� �̿��ϸ� �˾Ƽ� �ߺ��� ��������.
//�ߺ� �˻��� �ʿ䵵 ���� �� ����.

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