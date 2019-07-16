#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15661 //��ũ�� ��ŸƮ ���̵��ڡ�
//��͸� ����ؼ� ��� �κ��� �鷯�� �Ұ� ����.
int map[20][20];
bool team[20]; //true, false�� ���� ������.
int member, m_Min = 99999999;//������ ū ���� �־�д�.

void GetTeamScore(int numberMem, int Acnt, int Bcnt) {
	if (numberMem == member) { //�ο��� ��� ���������� ��.
		if (Acnt == 0 || Bcnt == 0) //�Ѹ� �������� �����Ѵ�.
			return;
		int aScore = 0, bScore = 0;
		for (int i = 0; i < member; i++) {
			for (int j = 0; j < member; j++) {
				if (team[i] && team[j])
					aScore += map[i][j]; // map[i][j]�� [j][i]�� ���ϸ� Ʋ��... �ֱ׷��Ŵ�
				else if (!team[i] && !team[j])
					bScore += map[i][j];
			}
		}
		if (m_Min > abs(aScore - bScore))
			m_Min = abs(aScore - bScore);
		return;
	}

	//���⼭ ���� �ȳ������ٸ�.
	team[numberMem] = true; //1�� ��Ȳ�϶�
	GetTeamScore(numberMem + 1, Acnt + 1, Bcnt);
	team[numberMem] = false;
	GetTeamScore(numberMem + 1, Acnt, Bcnt + 1);
	//�̷��� ���� ��Ȳ���� ����Ȳ�� ���� �� �ִ�.
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