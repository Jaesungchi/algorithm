#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/12100 2048(easy)
//Ǫ�µ� �̵���Ű�°� ������� �������½� ����

int N, maps[21][21], m_max = 0;
bool flagmaps[21][21];

void moves(int counts) {
	if (counts == 5) { //5ȸ �� �̵� ��
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				m_max = m_max > maps[i][j] ? m_max : maps[i][j];
			}
		return;
	}
	int tmaps[21][21];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			tmaps[i][j] = maps[i][j];
			flagmaps[i][j] = false;
		} //���� �ϴ� ������ ��.
	//����
	for (int i = 1; i < N; i++) { //������ �̵��� ����.
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) continue; //0�̸� �Ѿ
			for (int z = 1; i - z >= 0; z++) { //���� �ø�
				if (maps[i - z][j] != 0) { //���� ���ڰ� �ִµ�
					if (maps[i - z][j] == maps[i - z + 1][j] && !flagmaps[i-z][j]) { //���ڰ� ���ٸ�
						maps[i - z][j] *= 2; //2���� ��.
						maps[i - z + 1][j] = 0;
						flagmaps[i - z][j] = true;
						break;
					}
					else break; //���ڰ� �ٸ��� �̵� ����.
				}
				else {
					maps[i - z][j] = maps[i - z + 1][j]; //�Ʒ��� �ִ°� ���� �ű��
					maps[i - z + 1][j] = 0;// �Ʒ��Ŵ� 0���� �Ѵ�.
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//�Ʒ���
	for (int i = N-2; i >= 0; i--) { //�� �Ʒ��� �̵��� ����.
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) continue; //0�̸� �Ѿ
			for (int z = 1; i + z < N; z++) { //���� �ø�
				if (maps[i + z][j] != 0) { //�Ʒ��� ���ڰ� �ִµ�
					if (maps[i + z][j] == maps[i + z - 1][j]&&!flagmaps[i+z][j]) { //���ڰ� ���ٸ�
						maps[i + z][j] *= 2; //2���� ��.
						maps[i + z - 1][j] = 0;
						flagmaps[i + z][j] = true;
						break;
					}
					else break; //���ڰ� �ٸ��� �̵� ����.
				}
				else {
					maps[i + z][j] = maps[i + z - 1][j]; //�Ʒ��� �ִ°� ���� �ű��
					maps[i + z - 1][j] = 0;// �Ʒ��Ŵ� 0���� �Ѵ�.
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//��������
	for (int i = 0; i < N; i++) { 
		for (int j = 1; j < N; j++) { //�ǿ����� �̵��� ����.
			if (maps[i][j] == 0) continue; //0�̸� �Ѿ
			for (int z = 1; j - z >= 0; z++) { //�������� �������� �� �ø�
				if (maps[i][j-z] != 0) { //���ʿ� ���ڰ� �ִµ�
					if (maps[i][j-z] == maps[i][j-z+1] && !flagmaps[i][j-z]) { //���ڰ� ���ٸ�
						maps[i][j-z] *= 2; //2���� ��.
						maps[i][j-z+1] = 0;
						flagmaps[i][j-z] = true;
						break;
					}
					else break; //���ڰ� �ٸ��� �̵� ����.
				}
				else {
					maps[i][j-z] = maps[i][j-z+1]; 
					maps[i][j-z+1] = 0;
				}
			}
		}
	}
	moves(counts + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			maps[i][j] = tmaps[i][j];
			flagmaps[i][j] = false;
		}
	//����������
	for (int i = 0; i < N; i++) { 
		for (int j = N - 2; j >= 0; j--) {//�� �������� �̵��� ����.
			if (maps[i][j] == 0) continue; //0�̸� �Ѿ
			for (int z = 1; j + z < N; z++) { //���������� �������� ����
				if (maps[i][j+z] != 0) { //�����ʿ� ���ڰ� �ִµ�
					if (maps[i][j+z] == maps[i][j+z-1] && !flagmaps[i][j+z]) { //���ڰ� ���ٸ�
						maps[i][j+z] *= 2; //2���� ��.
						maps[i][j+z-1] = 0;
						flagmaps[i][j+z] = true;
						break;
					}
					else break; //���ڰ� �ٸ��� �̵� ����.
				}
				else {
					maps[i][j+z] = maps[i][j+z-1]; 
					maps[i][j+z-1] = 0;
				}
			}
		}
	}
	moves(counts + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> maps[i][j];
	moves(0);
	cout << m_max << "\n";
}