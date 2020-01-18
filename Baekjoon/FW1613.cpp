#include <iostream>
#define NONE 0
#define FUTURE 1
#define PAST -1
using namespace std;

//[역사 난이도★★★★](https://www.acmicpc.net/problem/1613)

int N, M; //사건 갯수 N, 관계의 수 K
int maps[401][401]; // 0 은 관계모름, -1 은 과거의일 1 은 미래 일

//Floyd-Warshall
void solve() {
	for (int k = 1; k <= N; k++)//중간점
		for (int i = 1; i <= N; i++)//시작점
			for (int j = 1; j <= N; j++) //끝점
				if (maps[i][j] == NONE) { //관계가 있다면 넘어감
					if (maps[i][k] == FUTURE && maps[k][j] == FUTURE)
						maps[i][j] = FUTURE;
					else if (maps[i][k] == PAST && maps[k][j] == PAST)
						maps[i][j] = PAST;
				}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp1, tmp2, Qcount; //Qcount 는 문제의 갯수
	bool isChange = true;// 변화가 있었으면 true
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		maps[tmp1][tmp2] = FUTURE; //tmp1 기준 tmp2가 미래의 일
		maps[tmp2][tmp1] = PAST; //tmp2 기준 tmp1은 과거의 일
	}
	solve();
	cin >> Qcount;
	while (Qcount-- > 0) {
		cin >> tmp1 >> tmp2;
		cout << maps[tmp2][tmp1] << "\n";
	}
}