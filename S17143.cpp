#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/17143 ���ÿ�
//�ð��ʰ� �ذ� �������.

int maps[101][101],tempmaps[101][101], R, C, M, shark[10001][5], dx[5] = { 0,0,0,1,-1 }, dy[5] = { 0,-1,1,0,0 },s_sum = 0;
//���ÿ��� ���������� ��ĭ �̵�
//���ÿ��� �ִ� ���� ����� ���� ���尡��� �� ��´�
//�� �̵��Ѵ�.

void CopyMap() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			maps[i][j] = tempmaps[i][j];
			tempmaps[i][j] = 0;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) { //�⺻���� ���� 0�̶� 1���� ��� ����
		cin >> shark[i][0] >> shark[i][1] >> shark[i][2] >> shark[i][3] >> shark[i][4];
		maps[shark[i][0]][shark[i][1]] = i; //����� ��ȣ�� �ʿ� ����.
		if (shark[i][3] >= 3) //dx����
			shark[i][2] %= (C * 2 - 2); //�Ÿ��� ���� �������� �������� ������ �ð� ����. 
		else
			shark[i][2] %= (R * 2 - 2);
	}
	// 0�� R, 1�� C, 2�� �ӵ�, 3�� ����, 4�� ũ��
	for (int i = 1; i <= C; i++) { // ����ŭ �̵�.
		for (int j = 1; j <= R; j++) { //�̵��� �� ���� �ִ� �� Ȯ���Ѵ�.
			if (maps[j][i] != 0) {
				s_sum += shark[maps[j][i]][4]; //ũ�⸦ ���ϰ�
				for(int z = 0 ; z < 5; z++) //�� �����.
					shark[maps[j][i]][z] = 0; //��ġ�� 0 �̸� ��������
				maps[j][i] = 0;
				break; //�����⸦ ������.
			}
		}
		//���⼭ ���� �� �̵�.
		for (int z = 1; z <= M; z++) { //����� ������ŭ ����.
			if (shark[z][0] == 0) continue; //����� ��ġ�� 0�̸� �����Ŷ� ����
			for (int s = shark[z][2] ; s > 0; s--) { //����� �̵�
				int mx = shark[z][1] + dx[shark[z][3]];
				if (mx <= 0) { //���� 0���� �Ѿ��
					shark[z][3] = 3; //dx�� + 1 �� �ٲ۴�
					mx = 2; //��ġ�� �ݴ����
				}
				else if (mx > C) {
					shark[z][3] = 4; //dx�� - 1 �� �ٲ۴�.
					mx = C - 1; 
				}
				int my = shark[z][0] + dy[shark[z][3]];
				if (my <= 0) { //���� 0���� �Ѿ��
					shark[z][3] = 2; //dy�� + 1 �� �ٲ۴�
					my = 2; //��ġ�� �ݴ����
				}
				else if (my > R) {
					shark[z][3] = 1;
					my = R - 1;
				}
				shark[z][0] = my;
				shark[z][1] = mx;
			}
			//�̵� �Ŀ�
			if (tempmaps[shark[z][0]][shark[z][1]] != 0) { //���ڸ��� ������ �ִٸ�
				if (shark[z][4] >= shark[tempmaps[shark[z][0]][shark[z][1]]][4]) {//���ο°� �� ũ��
					shark[tempmaps[shark[z][0]][shark[z][1]]][0] = 0;
					shark[tempmaps[shark[z][0]][shark[z][1]]][1] = 0; //������ ���ְ�
					tempmaps[shark[z][0]][shark[z][1]] = z; //���ο�� ����Ѵ�.	
				}
				else {
					shark[z][0] = 0;
					shark[z][1] = 0; //���ο�� ���ش�.
				}
			}
			else { //�ƹ��� ���ٸ�.
				tempmaps[shark[z][0]][shark[z][1]] = z; //���ο�� ����Ѵ�.
			}
		}
		//��� �̵������� �ӽ� �ʿ��� ���� ������ �ű��.
		CopyMap();
	}
	cout << s_sum << "\n";
}