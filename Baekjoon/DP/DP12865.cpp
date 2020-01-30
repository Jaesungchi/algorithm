#include <iostream>
#include <algorithm>
using namespace std;

//[평범한 배낭 난이도★★](https://www.acmicpc.net/problem/12865)

typedef struct thing {
	int weight;
	int value;
}T;

int N, mMax; //물건 수, 최대무게
T arr[101];
int DP[100001];

bool compare(T a, T b) {
	if (a.weight != b.weight)
		return a.weight < b.weight;
	return a.value > b.value; //가치는 높은거 먼저
}

int main() {
	cin >> N >> mMax;
	for (int i = 0; i < N; i++)
		cin >> arr[i].weight >> arr[i].value;
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
		for (int j = mMax; j >= arr[i].weight; j--)
			DP[j] = max(DP[j], DP[j - arr[i].weight] + arr[i].value);
	cout << DP[mMax] << "\n";
}