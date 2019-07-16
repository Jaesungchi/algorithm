#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15661 //링크와 스타트 난이도★★
//재귀를 사용해서 모든 부분을 들러야 할것 같음.
int map[20][20];
bool team[20]; //true, false로 팀을 나눈다.
int member, m_Min = 99999999;//임의의 큰 수를 넣어둔다.

void GetTeamScore(int numberMem, int Acnt, int Bcnt) {
	if (numberMem == member) { //인원이 모두 나눠졌을때 들어감.
		if (Acnt == 0 || Bcnt == 0) //한명도 없는팀은 무시한다.
			return;
		int aScore = 0, bScore = 0;
		for (int i = 0; i < member; i++) {
			for (int j = 0; j < member; j++) {
				if (team[i] && team[j])
					aScore += map[i][j]; // map[i][j]를 [j][i]도 더하면 틀림... 왜그런거니
				else if (!team[i] && !team[j])
					bScore += map[i][j];
			}
		}
		if (m_Min > abs(aScore - bScore))
			m_Min = abs(aScore - bScore);
		return;
	}

	//여기서 부터 안나눠졌다면.
	team[numberMem] = true; //1팀 상황일때
	GetTeamScore(numberMem + 1, Acnt + 1, Bcnt);
	team[numberMem] = false;
	GetTeamScore(numberMem + 1, Acnt, Bcnt + 1);
	//이렇게 위에 상황으로 모든상황을 나눌 수 있다.
}

int main() {
	cin >> member;
	for (int i = 0; i < member; i++) {
		for (int j = 0; j < member; j++) {
			cin >> map[i][j];
		}
	}
	GetTeamScore(0, 0, 0);
	cout << m_Min;

	return 0;
}