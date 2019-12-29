#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1149 RGB�Ÿ�

//���� ��ȹ�� ���� �ð� �ʰ��� �����ؾ��ϸ� DP�� Ǯ����Ѵ�.
//dfs�� Ǯ�� �ð� �ʰ� �ǹǷ� Ǯ�� ����.
//���� ������ �����ؼ� �̸� ù��°���Ͱ� �ƴ� �ι�° ���� ���� �����ؼ� �����ϸ鼭 �Ѵ�.
//������������ ������ ����� ����
int N, map[1001][3] = { 0,0,0, }, dP[1001][3] = { 0,0,0, };

int min(int x,int y) {
	return x < y ? x : y;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];
	for (int i = 1; i <= N; i++) {
		dP[i][0] = min(dP[i - 1][1], dP[i - 1][2]) + map[i][0];
		dP[i][1] = min(dP[i - 1][0], dP[i - 1][2]) + map[i][1];
		dP[i][2] = min(dP[i - 1][0], dP[i - 1][1]) + map[i][2];
	}
	cout << min(min(dP[N][0],dP[N][1]),dP[N][2]);
}