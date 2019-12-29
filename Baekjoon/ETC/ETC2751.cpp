#include <iostream>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/2751 수정렬하기2
//기존 버블소트는 시간 초과 됨
//알고리즘 라이브러리의 sort를 잘 활용하자.
//solve : 17:25 //검색의 힘...

int N, datas[1000001], temp;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i];
	sort(datas, datas + N);
	for (int i = 0; i < N; i++)
		cout << datas[i] << "\n";
	return 0;
}