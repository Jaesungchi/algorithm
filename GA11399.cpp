#include <vector>
#include <iostream>
using namespace std;
//그리드 알고리즘 문제
//https://www.acmicpc.net/problem/11399 ATM

int main() {
	int N,tmp,sums = 0;
	vector<int> arr; //데이터를 저장할 벡터
	vector<bool> arrbool;
	vector<int> outs;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		arrbool.push_back(true);
	}
	//알고리즘 시작
	for (int i = 0; i < N; i++) {
		int mins = 1001,mi = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (!arrbool[j]) //이미 꺼낸 숫자라면
				continue; //넘어간다.
			if (mins > arr[j]) { //min 보다 작은경우
				mi = j;
				mins = arr[j];
			}
		}
		arrbool[mi] = false;
		outs.push_back(sums + arr[mi]);
		sums += arr[mi];
	}
	sums = 0;
	for (int i = 0; i < outs.size(); i++)
		sums += outs[i];
	cout << sums << "\n"; 
}