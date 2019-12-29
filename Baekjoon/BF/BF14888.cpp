#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14888 연산자끼워넣기
//생각보다 쉽게 한방에 품

int N, datas[101], ydata[4], m_max = -1000000001, m_min = 1000000001 ,yunsan[100];;

void run(int counts,int nullCount,int n[100]) {
	if (counts == N-1) {
		int temps = datas[0];
		for (int i = 0; i < N - 1; i++) {
			switch (n[i]) {
			case 1://더하기
				temps += datas[i + 1];
				break;
			case 2://빼기
				temps -= datas[i + 1];
				break;
			case 3://곱하기
				temps *= datas[i + 1];
				break;
			case 4://나누기
				temps /= datas[i + 1];
				break;
			}
		}
		if (m_max < temps)
			m_max = temps;
		if (m_min > temps)
			m_min = temps;
		return;
	}
	else if (nullCount == N - 1) return; //계속 헛돌지 않게 함.
	if (ydata[0] > 0) { //1은 더하기 더하기가 0보다 크면
		n[counts] = 1;
		ydata[0]--;
		run(counts + 1,nullCount, yunsan);
		n[counts] = 0;
		ydata[0]++;
	}
	if (ydata[1] > 0) { //2는 빼기
		n[counts] = 2;
		ydata[1]--;
		run(counts + 1, nullCount, yunsan);
		n[counts] = 0;
		ydata[1]++;
	}
	if (ydata[2] > 0) { //3은 곱하기
		n[counts] = 3;
		ydata[2]--;
		run(counts + 1, nullCount, yunsan);
		n[counts] = 0;
		ydata[2]++;
	}
	if (ydata[3] > 0) { //4는 나누기
		n[counts] = 4;
		ydata[3]--;
		run(counts + 1, nullCount, yunsan);
		n[counts] = 0;
		ydata[3]++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> datas[i];
	for (int i = 0; i < 4; i++)
		cin >> ydata[i];
	
	run(0,0,yunsan);
	cout << m_max << "\n" << m_min << "\n";
}