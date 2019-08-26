#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14888 �����ڳ����ֱ�
//�������� ���� �ѹ濡 ǰ

int N, datas[101], ydata[4], m_max = -1000000001, m_min = 1000000001 ,yunsan[100];;

void run(int counts,int nullCount,int n[100]) {
	if (counts == N-1) {
		int temps = datas[0];
		for (int i = 0; i < N - 1; i++) {
			switch (n[i]) {
			case 1://���ϱ�
				temps += datas[i + 1];
				break;
			case 2://����
				temps -= datas[i + 1];
				break;
			case 3://���ϱ�
				temps *= datas[i + 1];
				break;
			case 4://������
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
	else if (nullCount == N - 1) return; //��� �굹�� �ʰ� ��.
	if (ydata[0] > 0) { //1�� ���ϱ� ���ϱⰡ 0���� ũ��
		n[counts] = 1;
		ydata[0]--;
		run(counts + 1,nullCount, yunsan);
		n[counts] = 0;
		ydata[0]++;
	}
	if (ydata[1] > 0) { //2�� ����
		n[counts] = 2;
		ydata[1]--;
		run(counts + 1, nullCount, yunsan);
		n[counts] = 0;
		ydata[1]++;
	}
	if (ydata[2] > 0) { //3�� ���ϱ�
		n[counts] = 3;
		ydata[2]--;
		run(counts + 1, nullCount, yunsan);
		n[counts] = 0;
		ydata[2]++;
	}
	if (ydata[3] > 0) { //4�� ������
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