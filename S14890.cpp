#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14890

int map[100][100];
int N;
int L;
int cnt = 0;

int main() {
	cin >> N >> L; //데이터를 받는다
	bool jok = true, iok = true;
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		jok = true;
		for (int j = 1; j < N; j++) {
			if (abs(map[i][j] - map[i][j - 1]) > 1) { //1보다 크게 차이나는경우 연결 끊어짐
				jok = false;
				break;
			}
			else if (abs(map[i][j] - map[i][j - 1]) == 1) {
				if (map[i][j-1] > map[i][j]) { //전에게 큰경우 다리를 j ++ 로 만든다
					for (int k = 0; k < L; k++) { //연결할 길이만큼 충분한지 확인
						if (map[i][j] != map[i][j + k] || j + k >= N) {
							jok = false;
							break;
						}
					}
				}
				else { //전에가 작은경우 다리를 j--로 만든다.
					for (int k = 0; k < L; k++) { //연결할 길이만큼 충분한지 확인
						if (map[i][j - 1] != map[i][j - 1 - k] || j - 1 - k < 0) {
							jok = false;
							break;
						}
					} 
					for (int k = 0; k < L; k++) {
						if (jok && j - L - k - 1 >= 0 && map[i][j - L - k-1] - map[i][j - L-k] == 1) //전이 충분하지만  이미 전에 사다리를 놓았는지 확인
							jok = false;
					}
				}
			}
		}
		if (jok)//연결이 끊어졌었는지 확인
			cnt += 1;
	}

	for (int i = 0; i < N; i++) {
		iok = true;
		for (int j = 1; j < N; j++) {
			if (abs(map[j][i] - map[j - 1][i]) > 1) { //1보다 크게 차이나는경우 연결 끊어짐
				iok = false;
				break;
			}
			else if (abs(map[j][i] - map[j - 1][i]) == 1) {
				if (map[j - 1][i] > map[j][i]) { //전에게 큰경우 다리를 j ++ 로 만든다
					for (int k = 0; k < L; k++) { //연결할 길이만큼 충분한지 확인
						if (map[j][i] != map[j + k][i] || j + k >= N)
							iok = false;
					}
				}
				else { //전에가 작은경우 다리를 j--로 만든다.
					for (int k = 0; k < L; k++) { //연결할 길이만큼 충분한지 확인
						if (map[j - 1][i] != map[j - 1 - k][i] || j - 1 - k < 0)
							iok = false;
					}
					for (int k = 0; k < L; k++) {
						if (iok &&j-L-k-1 >= 0 &&map[j - L-k-1][i] - map[j - L - k][i] == 1) //전이 충분하지만  이미 전에 사다리를 놓았는지 확인
							iok = false;
					}
				}
			}
		}
		if (iok) //연결이 끊어졌었는지 확인
			cnt += 1;
		
	}
	
	cout << cnt;
}