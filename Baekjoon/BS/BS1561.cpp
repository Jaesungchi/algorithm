#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//[놀이공원 난이도★★★](https://www.acmicpc.net/problem/1561)

int N, M; // 1 <= N <= 2,000,000,000 , 1 <= M <= 10,000
vector<int> arr;

//이분탐색으로 애들이 다 들어가는 시간대를 찾는다.
long long bs() {
	long long left = 0, right = 2000000000LL * 30LL;
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long tmp = M;
		for (int i = 0; i < M; i++)
			tmp += mid / arr[i];
		if (tmp >= N) {
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ttmp;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ttmp;
		arr.push_back(ttmp);
	}

	//놀이기구가 인원수보다 많은경우.
	if (N <= M) {
		cout << N << "\n";
		return 0;
	}

	long long finish = bs();
	long long tmp = M;
	for (int i = 0; i < M; i++) //다시 몇번째인지 알기위해 더한다.
		tmp += (finish - 1) / arr[i];
	for (int i = 0; i < M; i++) {
		if (!(finish % arr[i]))
			tmp++;
		if (tmp == N) {
			cout << i + 1;
			break;
		}
	}

}