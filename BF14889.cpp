#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14889 ��ŸƮ�� ��ũ
//�������� DFS ����

int map[21][21], N, m_min = 9999999, teamMap[21];

void dfs(int number, int teamA, int teamB) {
	if (number == N) { //�ο����� ������
		if (teamA != teamB) //�� �ο����� ���� �ʴٸ�
			return;
		int teamAS = 0, teamBS = 0;
		for (int i = 0; i < N - 1; i++) { //������ �� ���Ѵ�.
			for (int j = i; j < N; j++)
				if (teamMap[i] == teamMap[j])
					if (teamMap[i] == -1)
						teamAS += map[i][j] + map[j][i];
					else
						teamBS += map[i][j] + map[j][i];
		}
		m_min = m_min < abs(teamAS - teamBS) ? m_min : abs(teamAS - teamBS);
		return;
	}
	teamMap[number] = -1; //���� �����ϴ� �迭 -1 �� A�� 1 �� B��
	dfs(number + 1, teamA + 1, teamB);
	teamMap[number] = 1;
	dfs(number + 1, teamA, teamB + 1);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	dfs(0, 0, 0);
	cout << m_min << "\n";
}