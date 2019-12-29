#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15683 //����

int maps[9][9], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, N, M, m_min =9999999;
int cctv[8][3], cctvCnt=0; //cctv 0 = y , 1 = x, 2 = �����;

void Search(int mx, int my, int dir, int dir2) {
	while (true) { //�ϴ� �� �������� ����
		mx += dx[(dir + dir2) % 4];
		my += dy[(dir + dir2) % 4];
		if (mx < 0 || my < 0 || mx >= M || my >= N)
			break;
		if (maps[my][mx] == 6) //���� ���
			break;
		maps[my][mx] = 7;
	}
}

void RunCCTV(int dir,int cctvNum) {
	int mx = cctv[cctvNum][1];
	int my = cctv[cctvNum][0];
	int what = cctv[cctvNum][2];

	Search(mx, my, dir, 0);
	switch (what) {
	case 2: //�� ��
		Search(mx, my, dir, 2);
		break;
	case 3:
		Search(mx, my, dir, 3);
		break;
	case 4:
		Search(mx, my, dir, 2);
		Search(mx, my, dir, 3);
		break;
	case 5:
		Search(mx, my, dir, 1);
		Search(mx, my, dir, 2);
		Search(mx, my, dir, 3);
		break;
	default:
		break;
	}
}


void Runs(int counts) {
	if (cctvCnt == counts) {
		int s_sum = 0;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (maps[i][j] == 0) //���� �� ���鼭 ��ĭ�� �����´�.
					s_sum++;
		if (m_min > s_sum) { //
			m_min = s_sum; 
		}
		return;
	}
	
	int tmaps[9][9];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmaps[i][j] = maps[i][j];
	for (int k = 0; k < 4; k++) {
		RunCCTV(k, counts);
		Runs(counts + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				maps[i][j] = tmaps[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] > 0 && maps[i][j] < 6) {
				cctv[cctvCnt][0] = i;// y��ǥ
				cctv[cctvCnt][1] = j;// x��ǥ
				cctv[cctvCnt][2] = maps[i][j]; //cctv ����
				cctvCnt++;
			}
		}
	Runs(0);
	cout << m_min << "\n";
}
