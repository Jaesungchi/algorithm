#include <iostream>
#include <algorithm>
using namespace std;

//[고층 건물 난이도★★](https://www.acmicpc.net/problem/1027)
/*
	건물이 높을수도 있고 낮을 수 도 있다는것을 생각해야하는 문제.
	double 에는 1.0을 곱해야 소수점이 붙는다.
*/

int N; //1<= N <= 50;
int arr[51];
bool check[51][51]; //서로 볼 수있는지
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp,output = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		double dis = -1000000001 * 1.0;
		int cnt = 0;
		for (int j = i + 1; j < N; j++) {
			double tmp2 = 1.0 * (arr[j] - arr[i]) / (j - i);
			if (dis < tmp2) {
				dis = tmp2;
				cnt++;
				check[i][j] = true;
			}
		}
		for (int j = 0; j < i; j++)
			if (check[j][i])
				cnt++;
		output = max(cnt, output);
	}
	cout << output << "\n";
}