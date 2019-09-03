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
			if (maps[i][j] == 1) //벽은 1
				tmaps[i][j] = 1;
			else if (maps[i][j] == 2) //바이러스는 -1
				tmaps[i][j] = -1;
			else //그냥땅은 0
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
	if (counts == M) { //번호 만큼 추가 되면.
		queue<virus> Vir;
		int m_max = 0;
		for (int i = 0; i < virusCnt; i++)
			if (virusOn[i]) {
				virus temps = { virusMap[i][0],virusMap[i][1],1 };
				Vir.push(temps);
			}
		ResetMap();
		while (!Vir.empty()) { // 반복
			virus mt = Vir.front(); //맨앞에 거를 들고 나온다.
			Vir.pop();
			if (tmaps[mt.y][mt.x] > 0) //이미 번호가 있으면 넘긴다. //하지만 바이러스라면 잡는다.
				continue;
			tmaps[mt.y][mt.x] = mt.second; //땅에 초를 넣는다.
			if(maps[mt.y][mt.x] != 2)
				m_max = m_max > mt.second ? m_max : mt.second; //최대값을 갱신한다.
			for (int i = 0; i < 4; i++) {
				int mx = mt.x + dx[i];
				int my = mt.y + dy[i];
				if (mx < 0 || my < 0 || mx >= N || my >= N) //맵을 넘어가면
					continue;
				if (tmaps[my][mx] > 0) //이미 다른것이 있는 자리라면
					continue;
				virus temps = { mx,my,mt.second + 1 };
				Vir.push(temps);
			}
		}
		if (!Checkvoid()) //빈공간이 있다면.
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