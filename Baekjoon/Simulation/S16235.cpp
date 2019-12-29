#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/16235 //나무재태크
//다음엔 배열말고 벡터를 만들어서 사용하자.

int N,M,K,maps[11][11],treemap[11][11][1001],addmap[11][11],summermap[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
// N은 땅 크기 M은 나무 갯수 K는 년수.

void PrintTree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << treemap[i][j][0] << " ";
		}
		cout << "   ";
		for (int j = 0; j < N; j++) {
			cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//자신의 나이만큼 양분 먹고 나이 1증가.
//나이가 어린 나무부터 먹고 못먹으면 죽음.
void Spring() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int k = treemap[i][j][0];
			for (int m = k; m > 0; m--) { //새로 추가되는건 뒤에 있으므로 나이가 어림.
				if (maps[i][j] >= treemap[i][j][m]) { //나이보다 양분이 많다면
					maps[i][j] -= treemap[i][j][m];
					treemap[i][j][m]++; //나이를 한살 더 먹는다.
				}
				else { //양분이 부족하면 죽는다.
					int temp = treemap[i][j][m]/2;
					summermap[i][j] += temp; //여름에 비료로 주고.
					//죽은나무뒤에것들을 앞으로 땡김
					for (int b = m; b <= treemap[i][j][0]; b++) {
						treemap[i][j][b] = treemap[i][j][b + 1];
					}
					treemap[i][j][0]--; //총 나무에서 하나를 뺀다.
				}
			}
		}
}

//여름엔 죽은 나무가 양분으로 변한다. 나이를 2로나눈값이 양분으로 추가
void Summer() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] += summermap[i][j];
			summermap[i][j] = 0;
		}
}

//가을에는 번식
//5의 배수인 나무 인접한 8칸에 1인 나무 생성.
void fall() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int k = treemap[i][j][0];
			for (int m = k; m > 0; m--) {
				if (treemap[i][j][m] % 5 == 0) { //5의 배수이면.
					for (int z = 0; z < 8; z++) {
						int mx = j + dx[z];
						int my = i + dy[z];
						if (mx < 0 || my < 0 || mx >= N || my >= N)
							continue; //맵을 벗어나면 취소.
						treemap[my][mx][0]++; //갯수를 먼저늘리고
						treemap[my][mx][treemap[my][mx][0]] = 1; //그 자리에 1나무 생성
					}
				}
			}
		}
}

//겨울에는 양분 추가
void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			maps[i][j] += addmap[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			maps[i][j] = 5; //기본땅의 양분 설정
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin  >> addmap[i][j]; //앞으로 추가될 양분 설정.
	for (int i = 0; i < M; i++) { //나무설정
		int tx, ty, ta;
		cin >> tx >> ty >> ta;
		treemap[ty-1][tx-1][1] = ta; //-1은 r,c가 1부터 시작이기때문에
		treemap[ty-1][tx-1][0] = 1; //0번쨰는 현재 나무의 갯수를 넣는다.
	}
	for (int i = 0; i < K; i++) { //4계절
		Spring();
		Summer();
		fall();
		winter();
	}
	int countTree = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			countTree += treemap[i][j][0];
		}
	}
	cout << countTree << "\n";
}