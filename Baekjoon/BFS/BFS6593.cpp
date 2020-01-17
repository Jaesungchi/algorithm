#include <iostream>
#include <queue>
#include <string>
using namespace std;

//[상범빌딩 난이도★★★](https://www.acmicpc.net/problem/6593)

int L, R, C;//층 수 L, 세로 R, 가로 C
char maps[31][31][31]; //건물
//막힌 칸 '#' 비어있는칸 '.' 시작 'S', 출구 'E'
int dx[6] = { 0,0,0,0,-1,1 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 1,-1,0,0,0,0 }; //벡터값

typedef struct member {
	int L, R, C; //현재 위치
	int counts; //몇번 만에 도착했는지
}M;

bool isOutMap(int z,int y , int x) {
	if (z < 0 || y < 0 || x < 0 || z >= L || y >= R || x >= C)
		return true;
	return false;
}

string BFS(M starts) {
	bool checks[31][31][31] = { false, }; //들렀는지 아닌지
	bool isGoodEnd = false; //true면 잘 나감
	queue<M> q;
	checks[starts.L][starts.R][starts.C] = true; //들른부분.
	q.push(starts);
	while (!q.empty()) { //비지않았다면 계속
		M tmps = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int tL = tmps.L + dz[i];
			int tR = tmps.R + dy[i];
			int tC = tmps.C + dx[i];
			if (isOutMap(tL, tR, tC)) continue; //맵을 나가면 넘어감
			if (checks[tL][tR][tC]) continue; //들린곳이면 넘어감
			if (maps[tL][tR][tC] == '#') continue; //벽이면 넘어감
			else if (maps[tL][tR][tC] == 'E') {
				string output = "";
				output.append("Escaped in ");
				output.append(to_string(tmps.counts + 1));
				output.append(" minute(s).\n");
				return  output;
			}
			M news = { tL,tR,tC,tmps.counts + 1 };
			checks[tL][tR][tC] = true;
			q.push(news);
		}
	}
	return "Trapped!\n";
}

int main() {
	while (true) {
		M starts; //임시저장용
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) return 0; //종료
		for (int i = 0; i < L; i++) //맵 입력
			for (int j = 0; j < R; j++) {
				cin >> maps[i][j];
				for (int k = 0; k < C; k++)
					if (maps[i][j][k] == 'S')
						starts = { i,j,k,0 };
			}
		//BFS 부분
		cout << BFS(starts);
	}
}