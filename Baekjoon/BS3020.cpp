#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//[개똥벌래 난이도★★](https://www.acmicpc.net/problem/3020)
/*	
	이 문제는 홀수 짝수 배열을 따로 받아 정렬한 후.
	끝까지 의 값을 통해 찾을 수 있다.
*/

int N, H; //(2 <= N <= 200,000 , 2 <= H <= 500,000)
int arr1[250001]; //홀수 
int arr2[250001]; //짝수
int wall[500001]; //지나가는 벽의 갯수.
int minWall = 200001, minIndex = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N/2; i++) {
		cin >> arr1[i];
		cin >> arr2[i];
	}
	//정렬한다.
	sort(arr1, arr1 + N / 2);
	sort(arr2, arr2 + N / 2);
	int before = 0;
	//arr1을 돌며 넣는다.
	for (int i = 0; i < N / 2; i++) {
		if (arr2[i] == before)
			continue;
		else {
			for (int j = before; j < arr2[i]; j++)
				wall[H - j - 1] += N / 2 - i;
			before = arr2[i];
		}
	}
	//arr2를 돌며 넣는다.
	before = 0;
	for (int i = 0; i < N / 2; i++) {
		if (arr1[i] == before)
			continue;
		else {
			for (int j = before; j < arr1[i]; j++)
				wall[j] += N / 2 - i;
			before = arr1[i];
		}
	}
	for (int i = 0; i < H; i++) {
		if (minWall > wall[i]) {
			minWall = wall[i];
			minIndex = 1;
		}
		else if (minWall == wall[i])
			minIndex++;
	}
	cout << minWall << " " << minIndex;
}