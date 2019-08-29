#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15684 사다리 조작
//시간초과 관리가 힘들었음.

int N, M, H,hap = -1 ;
bool linemap[31][11];

bool sadari() {//사다리를 돌린다.
	for (int i = 1; i < N; i++) { //세로선 갯수만큼 간다. 맨마지막은 안돌려도 다 true면 true
		int pos = i;
		for (int j = 1; j <= H; j++) { //가면서 가로선을 하나씩 체크한다.
			if (linemap[j][pos]) { //오른쪽에 선이 있다면
				pos += 1; //포지션을+1 하고
				continue;  //한칸 아래로
			}
			else if (linemap[j][pos-1]) {//왼쪽에 선이 있다면
				pos -= 1; //포지션 -1 하고
				continue;
			}
		}
		if (pos != i) //같은곳에 가지 않으면
			return false;
	}
	return true; //다 같은곳으로 간다면.
}


void Runs(int counts,int y) {
	if (counts > 3) return;
	if (sadari()) {//사다리가 잘 돌아갔다면
		hap = hap > -1 ? hap > counts ? counts : hap : counts;
		return;
	}
	for (int i = y; i <= H; i++) {
		for (int j = 1; j < N; j++) { //선은 -1 개 있으므로
			if (linemap[i][j]) continue; //이미 선이 있는곳은 패스
			if (linemap[i][j - 1]) continue; //바로 왼쪽에 선이 있어도 패스
			if (linemap[i][j + 1]) continue; //바로 오른쪽에 선이 있어도 패스
			linemap[i][j] = true;
			Runs(counts + 1,i);
			linemap[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> H; //N은 세로선 H가 가로선
	for (int i = 1; i <= M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		linemap[temp1][temp2] = true; //사다리가 있는곳은 true
	}
	Runs(0,1);
	cout << hap << "\n";
}