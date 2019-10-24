#include <iostream>
using namespace std;

int  n, k, maps[201][2], datas[201] = { 0 }; //datas가 얼마나 쌓이는지 알려줌
int output = 201, outs[201], msum = 0, mins = 201, maxs = 0;
bool checks[201];
void runs(int index, int counts) {
	if (index == n) {
		int sums = 0;
		for (int i = mins; i <= maxs; i++) {
			if (datas[i] > k) //하나라도 크면 종료
				return;
			sums += datas[i];
		}
		if (counts < output && msum < sums) {
			int tmp = 0;
			for (int i = 0; i < n; i++)
				if (!checks[i])
					outs[tmp++] = i + 1;
			output = counts;
		}
		return;
	}
	checks[index] = false;
	runs(index + 1, counts + 1);
	for (int j = maps[index][0]; j <= maps[index][1]; j++)
		datas[j]++;
	checks[index] = true;
	runs(index + 1, counts);
	for (int j = maps[index][0]; j <= maps[index][1]; j++)
		datas[j]--;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> maps[i][0] >> maps[i][1];
		mins = mins > maps[i][0] ? maps[i][0] : mins;
		maxs = maxs < maps[i][1] ? maps[i][1] : maxs;
	}
	runs(0, 0);
	cout << output << "\n";
	for (int i = 0; i < output; i++)
		cout << outs[i] << " ";
}