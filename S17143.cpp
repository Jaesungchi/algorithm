#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/17143 낚시왕
//시간초과 해결 힘들었음.

int maps[101][101],tempmaps[101][101], R, C, M, shark[10001][5], dx[5] = { 0,0,0,1,-1 }, dy[5] = { 0,-1,1,0,0 },s_sum = 0;
//낚시왕이 오른쪽으로 한칸 이동
//낚시왕이 있는 열의 상어중 땅과 가장가까운 상어를 잡는다
//상어가 이동한다.

void CopyMap() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			maps[i][j] = tempmaps[i][j];
			tempmaps[i][j] = 0;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) { //기본으로 맵이 0이라 1부터 상어 시작
		cin >> shark[i][0] >> shark[i][1] >> shark[i][2] >> shark[i][3] >> shark[i][4];
		maps[shark[i][0]][shark[i][1]] = i; //상어의 번호를 맵에 저장.
		if (shark[i][3] >= 3) //dx방향
			shark[i][2] %= (C * 2 - 2); //거리로 나눈 나머지를 가져가는 이유는 시간 절약. 
		else
			shark[i][2] %= (R * 2 - 2);
	}
	// 0은 R, 1은 C, 2는 속도, 3은 방향, 4는 크기
	for (int i = 1; i <= C; i++) { // 열만큼 이동.
		for (int j = 1; j <= R; j++) { //이동후 그 열에 있는 상어를 확인한다.
			if (maps[j][i] != 0) {
				s_sum += shark[maps[j][i]][4]; //크기를 더하고
				for(int z = 0 ; z < 5; z++) //상어를 지운다.
					shark[maps[j][i]][z] = 0; //위치가 0 이면 지워진거
				maps[j][i] = 0;
				break; //상어잡기를 끝낸다.
			}
		}
		//여기서 부터 상어가 이동.
		for (int z = 1; z <= M; z++) { //상어의 갯수만큼 돈다.
			if (shark[z][0] == 0) continue; //상어의 위치가 0이면 먹은거라 무시
			for (int s = shark[z][2] ; s > 0; s--) { //상어의 이동
				int mx = shark[z][1] + dx[shark[z][3]];
				if (mx <= 0) { //맵을 0으로 넘어가면
					shark[z][3] = 3; //dx를 + 1 로 바꾼다
					mx = 2; //위치는 반대방향
				}
				else if (mx > C) {
					shark[z][3] = 4; //dx를 - 1 로 바꾼다.
					mx = C - 1; 
				}
				int my = shark[z][0] + dy[shark[z][3]];
				if (my <= 0) { //맵을 0으로 넘어가면
					shark[z][3] = 2; //dy를 + 1 로 바꾼다
					my = 2; //위치는 반대방향
				}
				else if (my > R) {
					shark[z][3] = 1;
					my = R - 1;
				}
				shark[z][0] = my;
				shark[z][1] = mx;
			}
			//이동 후에
			if (tempmaps[shark[z][0]][shark[z][1]] != 0) { //그자리에 누군가 있다면
				if (shark[z][4] >= shark[tempmaps[shark[z][0]][shark[z][1]]][4]) {//새로온게 더 크면
					shark[tempmaps[shark[z][0]][shark[z][1]]][0] = 0;
					shark[tempmaps[shark[z][0]][shark[z][1]]][1] = 0; //먹힌걸 없애고
					tempmaps[shark[z][0]][shark[z][1]] = z; //새로운걸 등록한다.	
				}
				else {
					shark[z][0] = 0;
					shark[z][1] = 0; //새로운걸 없앤다.
				}
			}
			else { //아무도 없다면.
				tempmaps[shark[z][0]][shark[z][1]] = z; //새로운걸 등록한다.
			}
		}
		//상어 이동끝난후 임시 맵에서 현재 맵으로 옮긴다.
		CopyMap();
	}
	cout << s_sum << "\n";
}