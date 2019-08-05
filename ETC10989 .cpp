#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10989 수 정렬하기 3
//마냥 수정렬인줄 알았는데 메모리문제 심각함. 절대 10000000개를 배열에 못넣음
//문제에 힌트가 있었다.

int n, datas[10001],temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		datas[temp] ++;
	}

	for (int i = 1; i < 10001; i++)
		for(int j = 1; j <= datas[i];j++)
			cout << i << "\n";
}