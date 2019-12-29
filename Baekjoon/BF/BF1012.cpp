#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1012 유기농배추

int testCase; //테스트 케이스 변수
int M, N, countBaechu, countInsect = 0;
int map[51][51] = { 0 }; //맵사이즈가 최대 50이면 51까지 만들어준다.
int A, B; //잠시 변수를 저장하기 위한 A,B
int dx[4] = { 0,0,1,-1 }; // 4방향으로 빠르게 가기위한 배열
int dy[4] = { 1,-1,0,0 };

//4방향에 1이 있다면 먹고 그자리에서 한번더 확인하는 메소드
void SpreadInsect(int y,int x ){ 
	map[y][x] = 2;
	for (int i = 0; i < 4; i++)
		if (x + dx[i] >= 0 || x + dx[i] < M || y + dy[i] >= 0 || y + dy[i] < N)
			if (map[y + dy[i]][x + dx[i]] == 1)
				SpreadInsect(y + dy[i], x + dx[i]);
}

//배추 배열을 초기화 시켜주는 메소드
void initBaechu() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = 0;
}

int main() {
	cin >> testCase;
	while(testCase--) {
		cin >> M >> N >> countBaechu;
		initBaechu();
		for (int i = 0; i < countBaechu; i++) { //배추 데이터를 저장한다.
			cin >> A >> B;
			map[B][A] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) { //그자리가 배추만 있다면
					countInsect += 1; //곤충 수를 1 늘리고 
					SpreadInsect(i, j); //곤충을 뿌린다.
				}
			}
		}
		cout << countInsect << '\n';
		countInsect = 0;
	}
}