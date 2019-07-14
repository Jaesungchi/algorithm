#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14890

int map[100][100];
int N;
int L;
int cnt = 0;

int main() {
	cin >> N >> L; //�����͸� �޴´�
	bool jok = true, iok = true;
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		jok = true;
		for (int j = 1; j < N; j++) {
			if (abs(map[i][j] - map[i][j - 1]) > 1) { //1���� ũ�� ���̳��°�� ���� ������
				jok = false;
				break;
			}
			else if (abs(map[i][j] - map[i][j - 1]) == 1) {
				if (map[i][j-1] > map[i][j]) { //������ ū��� �ٸ��� j ++ �� �����
					for (int k = 0; k < L; k++) { //������ ���̸�ŭ ������� Ȯ��
						if (map[i][j] != map[i][j + k] || j + k >= N) {
							jok = false;
							break;
						}
					}
				}
				else { //������ ������� �ٸ��� j--�� �����.
					for (int k = 0; k < L; k++) { //������ ���̸�ŭ ������� Ȯ��
						if (map[i][j - 1] != map[i][j - 1 - k] || j - 1 - k < 0) {
							jok = false;
							break;
						}
					} 
					for (int k = 0; k < L; k++) {
						if (jok && j - L - k - 1 >= 0 && map[i][j - L - k-1] - map[i][j - L-k] == 1) //���� ���������  �̹� ���� ��ٸ��� ���Ҵ��� Ȯ��
							jok = false;
					}
				}
			}
		}
		if (jok)//������ ������������ Ȯ��
			cnt += 1;
	}

	for (int i = 0; i < N; i++) {
		iok = true;
		for (int j = 1; j < N; j++) {
			if (abs(map[j][i] - map[j - 1][i]) > 1) { //1���� ũ�� ���̳��°�� ���� ������
				iok = false;
				break;
			}
			else if (abs(map[j][i] - map[j - 1][i]) == 1) {
				if (map[j - 1][i] > map[j][i]) { //������ ū��� �ٸ��� j ++ �� �����
					for (int k = 0; k < L; k++) { //������ ���̸�ŭ ������� Ȯ��
						if (map[j][i] != map[j + k][i] || j + k >= N)
							iok = false;
					}
				}
				else { //������ ������� �ٸ��� j--�� �����.
					for (int k = 0; k < L; k++) { //������ ���̸�ŭ ������� Ȯ��
						if (map[j - 1][i] != map[j - 1 - k][i] || j - 1 - k < 0)
							iok = false;
					}
					for (int k = 0; k < L; k++) {
						if (iok &&j-L-k-1 >= 0 &&map[j - L-k-1][i] - map[j - L - k][i] == 1) //���� ���������  �̹� ���� ��ٸ��� ���Ҵ��� Ȯ��
							iok = false;
					}
				}
			}
		}
		if (iok) //������ ������������ Ȯ��
			cnt += 1;
		
	}
	
	cout << cnt;
}