#include <iostream>
#include <algorithm>
using namespace std;

//[반도체 설계 난이도★★★](https://www.acmicpc.net/problem/2352)

int N;
int arr[40001]; // 연결되는 포트 번호
int DP[40001]; // 인덱스만큼 연결되었을때 제일 오른쪽

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	DP[1] = arr[1];
	int length = 1; //연결 최대 가능
	for (int i = 2; i <= N; i++) { 
		if (DP[length] < arr[i]) { //이후 연결되는게 더 아래로 연결된다면
			DP[++length] = arr[i]; //연결 최대거리 추가하고 그 값을 넣어둔다.
			continue;
		}
		/*  lower_bound가 N Log N 소요됨
			배열에 사이즈를 반환함.(이게 곧 최대)
			3번째 파라미터를 기준으로 DP ~ DP + length까지 배열에서
			제일 길게 뽑을 수있는 lower_bound 값을 돌려줌
		*/
		int index = lower_bound(DP + 1, DP + length + 1, arr[i]) - DP;
		DP[index] = arr[i];
	}
	cout << length << "\n";
}