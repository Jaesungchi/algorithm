#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/15686 치킨배달
//dfs를 활용한 브루트포스 문제로 모든 치킨집을 채점 해보는데서 애를 먹었다.
//vector를 처음 활용한 알고리즘

int N, M, temp, ans = 9999999, selected[14];
vector<pair<int, int>> chic;
vector<pair<int, int>> house;

//selects는 치킨집을 전체를 돌기위한 숫자, idx는 몇개를 선택했는지 이다.
void dfs(int selects, int idx) {
	if (selects > chic.size())
		return;
	if (idx == M) {
		int m_sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int hx = house[i].first;
			int hy = house[i].second;
			int min = 9999999;
			for (int j = 0; j < idx; j++) {
				int cx = chic[selected[j]].first;
				int cy = chic[selected[j]].second;
				int aver = abs(hx - cx) + abs(hy - cy);
				if (aver < min) //min은 그 가정집이 제일 가까운 치킨집의 거리이다.
					min = aver;

			}
			m_sum += min;
		}
		if (m_sum < ans)
			ans = m_sum;
		return;
	}
	//이 밑을 돌면 0 1 2 , 1 2 3 , 2 5 7 등 이렇게 돌게 된다.
	selected[idx] = selects;
	dfs(selects + 1, idx + 1);
	selected[idx] = -1;
	dfs(selects + 1, idx);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1)
				house.push_back({ i,j });
			else if (temp == 2)
				chic.push_back({ i,j });
		}
	dfs(0, 0);
	cout << ans;
}