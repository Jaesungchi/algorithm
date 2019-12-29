#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/16235 //��������ũ
//������ �迭���� ���͸� ���� �������.

int N,M,K,maps[11][11],treemap[11][11][1001],addmap[11][11],summermap[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
// N�� �� ũ�� M�� ���� ���� K�� ���.

void PrintTree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << treemap[i][j][0] << " ";
		}
		cout << "   ";
		for (int j = 0; j < N; j++) {
			cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//�ڽ��� ���̸�ŭ ��� �԰� ���� 1����.
//���̰� � �������� �԰� �������� ����.
void Spring() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int k = treemap[i][j][0];
			for (int m = k; m > 0; m--) { //���� �߰��Ǵ°� �ڿ� �����Ƿ� ���̰� �.
				if (maps[i][j] >= treemap[i][j][m]) { //���̺��� ����� ���ٸ�
					maps[i][j] -= treemap[i][j][m];
					treemap[i][j][m]++; //���̸� �ѻ� �� �Դ´�.
				}
				else { //����� �����ϸ� �״´�.
					int temp = treemap[i][j][m]/2;
					summermap[i][j] += temp; //������ ���� �ְ�.
					//���������ڿ��͵��� ������ ����
					for (int b = m; b <= treemap[i][j][0]; b++) {
						treemap[i][j][b] = treemap[i][j][b + 1];
					}
					treemap[i][j][0]--; //�� �������� �ϳ��� ����.
				}
			}
		}
}

//������ ���� ������ ������� ���Ѵ�. ���̸� 2�γ������� ������� �߰�
void Summer() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] += summermap[i][j];
			summermap[i][j] = 0;
		}
}

//�������� ����
//5�� ����� ���� ������ 8ĭ�� 1�� ���� ����.
void fall() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int k = treemap[i][j][0];
			for (int m = k; m > 0; m--) {
				if (treemap[i][j][m] % 5 == 0) { //5�� ����̸�.
					for (int z = 0; z < 8; z++) {
						int mx = j + dx[z];
						int my = i + dy[z];
						if (mx < 0 || my < 0 || mx >= N || my >= N)
							continue; //���� ����� ���.
						treemap[my][mx][0]++; //������ �����ø���
						treemap[my][mx][treemap[my][mx][0]] = 1; //�� �ڸ��� 1���� ����
					}
				}
			}
		}
}

//�ܿ￡�� ��� �߰�
void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			maps[i][j] += addmap[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			maps[i][j] = 5; //�⺻���� ��� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin  >> addmap[i][j]; //������ �߰��� ��� ����.
	for (int i = 0; i < M; i++) { //��������
		int tx, ty, ta;
		cin >> tx >> ty >> ta;
		treemap[ty-1][tx-1][1] = ta; //-1�� r,c�� 1���� �����̱⶧����
		treemap[ty-1][tx-1][0] = 1; //0������ ���� ������ ������ �ִ´�.
	}
	for (int i = 0; i < K; i++) { //4����
		Spring();
		Summer();
		fall();
		winter();
	}
	int countTree = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			countTree += treemap[i][j][0];
		}
	}
	cout << countTree << "\n";
}