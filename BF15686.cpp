#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/15686 ġŲ���
//dfs�� Ȱ���� ���Ʈ���� ������ ��� ġŲ���� ä�� �غ��µ��� �ָ� �Ծ���.
//vector�� ó�� Ȱ���� �˰���

int N, M, temp, ans = 9999999, selected[14];
vector<pair<int, int>> chic;
vector<pair<int, int>> house;

//selects�� ġŲ���� ��ü�� �������� ����, idx�� ��� �����ߴ��� �̴�.
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
				if (aver < min) //min�� �� �������� ���� ����� ġŲ���� �Ÿ��̴�.
					min = aver;

			}
			m_sum += min;
		}
		if (m_sum < ans)
			ans = m_sum;
		return;
	}
	//�� ���� ���� 0 1 2 , 1 2 3 , 2 5 7 �� �̷��� ���� �ȴ�.
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