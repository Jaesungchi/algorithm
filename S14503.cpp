#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14503 로봇청소기
//후진했을때도 count를 추가하고 있었다 아놔 ;;

int N, M, map[51][51], dx[4] = { 0,1,0,-1 }, dy[4] = {-1,0,1,0},countClear = 0;
int mpX, mpY, mpD; //로봇의 위치 및 방향
//0 은 북 ,1은 동, 2는 남, 3은 서

void MoveRobot(int x, int y,int dir) {
	map[y][x] = 8; //청소

	//왼쪽 방향에 아직 청소하지 않은 공간이 있다면 그방향으로 회전한 다음 전진
	//왼쪽에 청소할공간이 없다면 왼쪽으로 회전
	for (int i = 0; i < 4; i++) {
		dir = (dir + 3) % 4; // -1한거랑 같음.
		int mx = x + dx[dir];
		int my = y + dy[dir];
		if (map[my][mx] == 0) { //빈땅이라면
			countClear++;
			MoveRobot(mx, my, dir);
			return;
		}
	}
	//네방향 전부 청소 되있거나 벽인경우 뒤로 1칸
	int mx = x + dx[(dir + 2) % 4]; //뒤로 한칸
	int my = y + dy[(dir + 2) % 4]; //뒤로 한칸
	//네방향 모두 청소되있는데 뒤도 벽인경우 작동 멈춤.
	if (map[my][mx] == 1) // 벽이라면
		return; //종료한다.
	MoveRobot(mx, my, dir);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> mpY >> mpX >> mpD;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	countClear++;
	MoveRobot(mpX, mpY, mpD);
	cout << countClear << "\n";
}