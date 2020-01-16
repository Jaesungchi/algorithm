#include <iostream>
#define EAST 1
#define WEST 3
#define NORTH 0
#define SOUTH 2
using namespace std;

//[로봇 시뮬레이션 난이도 ★★](https://www.acmicpc.net/problem/2174)

int A, B;// 가로 A 세로 B
int N, M;// 로봇 수 N 명령 수 M;
int mx[4] = { 0,1,0,-1 }, my[4] = { 1,0,-1,0 }; //방향

typedef struct robot {
	int x, y;
	int dir;
}R;

//충돌 확인
bool isCrushWall(int x, int y) {
	if (x <= 0 || y <= 0 || x > A || y > B)
		return true;
	return false;
}

bool isCrushRobot(R r1, R r2) {
	if (r1.x == r2.x && r1.y == r2.y)
		return true;
	return false;
}

int main() {
	int tmp1, tmp2;
	char tmp3; //방향이나 글자 임시 변수
	R robots[101];
	cin >> A >> B;
	cin >> N >> M;
	//로봇 입력
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		robots[i].x = tmp1;
		robots[i].y = tmp2;
		switch (tmp3) {
		case 'E':
			robots[i].dir = EAST;
			break;
		case 'W':
			robots[i].dir = WEST;
			break;
		case 'S':
			robots[i].dir = SOUTH;
			break;
		case 'N':
			robots[i].dir = NORTH;
			break;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp3 >> tmp2;
		tmp1 -= 1; //로봇의 배열이 0부터 시작
		switch (tmp3) {
		case 'F': //직진
			for (tmp2; tmp2 > 0; tmp2--) {
				int tx = robots[tmp1].x + mx[robots[tmp1].dir];
				int ty = robots[tmp1].y + my[robots[tmp1].dir];
				if (isCrushWall(tx, ty)) {//충돌 확인
					cout << "Robot " << tmp1+1 << " crashes into the wall\n";
					return 0;
				}
				robots[tmp1].x = tx;
				robots[tmp1].y = ty;
				for (int j = 0; j < N; j++) {
					if (j == tmp1) continue;
					if (isCrushRobot(robots[tmp1], robots[j])) {
						cout << "Robot " << tmp1 + 1 << " crashes into robot " << j + 1 << "\n";
						return 0;
					}
				}
			}
			break;
		case 'L': //좌회전
			for (tmp2; tmp2 > 0; tmp2--)
				robots[tmp1].dir = (robots[tmp1].dir + 3) % 4;
			break;
		case 'R': //우회전
			for(tmp2; tmp2 > 0; tmp2--)
				robots[tmp1].dir = (robots[tmp1].dir + 1) % 4;
 			break;
		}
	}
	cout << "OK" << "\n";
}