#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int three[10],datas[10000],checks= 0;
bool maps[10];
void Run(int index) { //모든 수를 미리 저장한다.
	if (index == 10) {
		int save = 0;
		for(int i = 0 ; i < 10 ; i++)
			if (maps[i])
				save += three[i];
		if (save > 19683)
			return;
		datas[checks++] = save;
		return;
	}
	maps[index] = true;
	Run(index+1);
	maps[index] = false;
	Run(index+1);
	return;
}

int main() {
	int n,arr[501],outs[501];
	cin >> n;
	for (int i = 0; i < 10; i++)
		three[i] = pow((double)3, (double)i);
	Run(0);
	sort(datas, datas+checks);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; ; j++)
			if (arr[i] <= datas[j]) {
				outs[i] = datas[j];
				break;
			}
	}
	for (int i = 0; i < n; i++)
		cout << outs[i] << "\n";
}