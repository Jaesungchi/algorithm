#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14889 스타트와 링크
//전형적인 DFS 문제

int map[21][21], N, m_min = 9999999, teamMap[21];

void dfs(int number, int teamA, int teamB) {
	if (number == N) { //인원수가 꽉차고
		if (teamA != teamB) //팀 인원수가 같지 않다면
			return;
		int teamAS = 0, teamBS = 0;
		for (int i = 0; i < N - 1; i++) { //점수를 다 더한다.
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
	teamMap[number] = -1; //팀을 저장하는 배열 -1 이 A팀 1 이 B팀
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