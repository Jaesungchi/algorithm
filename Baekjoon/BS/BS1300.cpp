#include<iostream>
#include <algorithm>
using namespace std;

//K번째 수(https://www.acmicpc.net/problem/1300)
//이분탐색
//1 2 3
//2 4 6    // 1 2 2 3 3 4 6 6 9
//3 6 9
int main() {
	int N, K,result = -1;
	cin >> N >> K;
	int left = 1, right = K; //left랑 right가 같아지거나 left가 커지면 찾음.

	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N); //mid보다 작은 숫자를 파악한다.
		if (cnt < K)
			left = mid + 1;
		else { //카운트 값이 많다는건 mid를 내려야함.
			result = mid;
			right = mid - 1;
		}
	}
	cout << result << "\n";
}