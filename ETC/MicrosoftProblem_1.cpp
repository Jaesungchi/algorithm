#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[101], n;
bool chk[101][101];
bool visits[101];

void DFS(int index, int cnt) {
	for (int i = 1; i <= n; i++) {
		if (chk[index][i]) {
			chk[index][i] = false;
			chk[i][index] = false;
			arr[cnt]++;
			if (!visits[i]) {
				visits[i] = true;
				DFS(i, cnt);
			}
		}
	}
}

int solution(vector<int> &A, vector<int> &B, int N) {
	n = N;
	int output = 0;
	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		chk[A[i]][B[i]] = true;
		chk[B[i]][A[i]] = true;
	}
	for (int i = 1; i <= N; i++)
		if (!visits[i])
			DFS(i, cnt++);
	for (int i = 0; i < N; i++) 
		output = arr[i] > output ? arr[i] : output;
	return output;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> aa;
	aa.push_back(1);
	aa.push_back(2);
	aa.push_back(4);
	aa.push_back(5);

	vector<int> bb;
	bb.push_back(2);
	bb.push_back(3);
	bb.push_back(5);
	bb.push_back(6);
	cout << solution(aa, bb, 6);
}