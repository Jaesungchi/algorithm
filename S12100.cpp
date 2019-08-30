#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/12100 2048(easy)
//푸는데 이동시키는게 힘들었음 나머지는쏘 이지

int N, maps[21][21], m_max = 0;
bool flagmaps[21][21];

void moves(int counts) {
	if (counts == 5) { //5회 다 이동 후
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				m_max = m_max > maps[i][j] ? m_max : maps[i][j];
			}
		return;
	}
	int tmaps[21][21];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			tmaps[i][j] = maps[i][j];
			flagmaps[i][j] = false;
		} //맵을 일단 복사한 뒤.
	//위로
	for (int i = 1; i < N; i++) { //맨위는 이동이 없음.
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) continue; //0이면 넘어감
			for (int z = 1; i - z >= 0; z++) { //위로 올림
				if (maps[i - z][j] != 0) { //위에 숫자가 있는데
					if (maps[i - z][j] == maps[i - z + 1][j] && !flagmaps[i-z][j]) { //숫자가 같다면
						maps[i - z][j] *= 2; //2배한 후.
						maps[i - z + 1][j] = 0;
						flagmaps[i - z][j] = true;
						break;
					}
					else break; //숫자가 다르면 이동 종료.
				}
				else {
					maps[i - z][j] = maps[i - z + 1][j]; //아래에 있는걸 위로 옮기고
					maps[i - z + 1][j] = 0;// 아래거는 0으로 한다.
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//아래로
	for (int i = N-2; i >= 0; i--) { //맨 아래는 이동이 없음.
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) continue; //0이면 넘어감
			for (int z = 1; i + z < N; z++) { //위로 올림
				if (maps[i + z][j] != 0) { //아래에 숫자가 있는데
					if (maps[i + z][j] == maps[i + z - 1][j]&&!flagmaps[i+z][j]) { //숫자가 같다면
						maps[i + z][j] *= 2; //2배한 후.
						maps[i + z - 1][j] = 0;
						flagmaps[i + z][j] = true;
						break;
					}
					else break; //숫자가 다르면 이동 종료.
				}
				else {
					maps[i + z][j] = maps[i + z - 1][j]; //아래에 있는걸 위로 옮기고
					maps[i + z - 1][j] = 0;// 아래거는 0으로 한다.
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//왼쪽으로
	for (int i = 0; i < N; i++) { 
		for (int j = 1; j < N; j++) { //맨왼쪽은 이동이 없음.
			if (maps[i][j] == 0) continue; //0이면 넘어감
			for (int z = 1; j - z >= 0; z++) { //왼쪽으로 가기위해 뺌 올림
				if (maps[i][j-z] != 0) { //왼쪽에 숫자가 있는데
					if (maps[i][j-z] == maps[i][j-z+1] && !flagmaps[i][j-z]) { //숫자가 같다면
						maps[i][j-z] *= 2; //2배한 후.
						maps[i][j-z+1] = 0;
						flagmaps[i][j-z] = true;
						break;
					}
					else break; //숫자가 다르면 이동 종료.
				}
				else {
					maps[i][j-z] = maps[i][j-z+1]; 
					maps[i][j-z+1] = 0;
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//오른쪽으로
	for (int i = 0; i < N; i++) { 
		for (int j = N - 2; j >= 0; j--) {//맨 오른쪽은 이동이 없음.
			if (maps[i][j] == 0) continue; //0이면 넘어감
			for (int z = 1; j + z < N; z++) { //오른쪽으로 가기위해 더함
				if (maps[i][j+z] != 0) { //오른쪽에 숫자가 있는데
					if (maps[i][j+z] == maps[i][j+z-1] && !flagmaps[i][j+z]) { //숫자가 같다면
						maps[i][j+z] *= 2; //2배한 후.
						maps[i][j+z-1] = 0;
						flagmaps[i][j+z] = true;
						break;
					}
					else break; //숫자가 다르면 이동 종료.
				}
				else {
					maps[i][j+z] = maps[i][j+z-1]; 
					maps[i][j+z-1] = 0;
				}
			}
		}
	}
	moves(counts + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> maps[i][j];
	moves(0);
	cout << m_max << "\n";
}