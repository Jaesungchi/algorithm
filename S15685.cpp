#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/15685 드래곤커브
//멍청하게 꼭짓점만 들어가면 되는걸 선이 다 들어가야 된다 생각함 ;;
//드래곤커브 규칙을 써가면서 하니깐 금방 구함

int N, A, B, C, D, sums = 0;
bool map[101][101];
vector<int> dir;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C >> D;
		dir.push_back(C);
		for (int i = 0; i < D; i++) //세대만큼 구한다.
			for (int j = dir.size() - 1; j >= 0; j--) // ex)2세대는 1세대의 맨 뒤부터 +1 그전거 +1 된거
				dir.push_back((dir[j] + 1) % 4);
		map[B][A] = true;
		for (int i = 0; i < dir.size(); i++) {
			switch (dir[i]) {
			case 0:
				A++;
				break;
			case 1:
				B--;
				break;
			case 2:
				A--;
				break;
			case 3:
				B++;
				break;
			}
			map[B][A] = true;
		}
		dir.clear();
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				sums++;
	cout << sums;
}