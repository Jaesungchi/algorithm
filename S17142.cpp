#include <iostream>
#include <queue>
using namespace std;

int maps[51][51], N, M, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, virusMap[10][2],virusCnt = 0;
int tmaps[51][51], m_min = -1;
bool virusOn[11];

void PrintMap() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << tmaps[i][j] << " ";
		cout << "\n";
	}
}

void ResetMap() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 1) //���� 1
				tmaps[i][j] = 1;
			else if (maps[i][j] == 2) //���̷����� -1
				tmaps[i][j] = -1;
			else //�׳ɶ��� 0
				tmaps[i][j] = 0;
		}
}

bool Checkvoid() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (tmaps[i][j] == 0) return false;
	return true;
}

struct virus {
	int x, y;
	int second;
};

void Runs(int counts,int numbers) {
	if (counts == M) { //��ȣ ��ŭ �߰� �Ǹ�.
		queue<virus> Vir;
		int m_max = 0;
		for (int i = 0; i < virusCnt; i++)
			if (virusOn[i]) {
				virus temps = { virusMap[i][0],virusMap[i][1],1 };
				Vir.push(temps);
			}
		ResetMap();
		while (!Vir.empty()) { // �ݺ�
			virus mt = Vir.front(); //�Ǿտ� �Ÿ� ��� ���´�.
			Vir.pop();
			if (tmaps[mt.y][mt.x] > 0) //�̹� ��ȣ�� ������ �ѱ��. //������ ���̷������ ��´�.
				continue;
			tmaps[mt.y][mt.x] = mt.second; //���� �ʸ� �ִ´�.
			if(maps[mt.y][mt.x] != 2)
				m_max = m_max > mt.second ? m_max : mt.second; //�ִ밪�� �����Ѵ�.
			for (int i = 0; i < 4; i++) {
				int mx = mt.x + dx[i];
				int my = mt.y + dy[i];
				if (mx < 0 || my < 0 || mx >= N || my >= N) //���� �Ѿ��
					continue;
				if (tmaps[my][mx] > 0) //�̹� �ٸ����� �ִ� �ڸ����
					continue;
				virus temps = { mx,my,mt.second + 1 };
				Vir.push(temps);
			}
		}
		if (!Checkvoid()) //������� �ִٸ�.
			return;
		if (m_min > m_max || m_min == -1) {
			m_min = m_max;
			PrintMap();
		}
		return;
	}
	if (numbers + 1 == virusCnt)
		return;
	virusOn[numbers] = true;
	Runs(counts + 1,numbers+1);
	virusOn[numbers] = false;
	Runs(counts,numbers +1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N ; i++)
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 2) {
				virusMap[virusCnt][0] = j;
				virusMap[virusCnt][1] = i;
				virusCnt++;
			}
		}
	Runs(0,0);
	if (m_min == -1)
		cout << m_min << "\n";
	else
		cout << m_min-1 << "\n";
	
}