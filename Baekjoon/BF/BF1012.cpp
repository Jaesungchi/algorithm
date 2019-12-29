#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1012 ��������

int testCase; //�׽�Ʈ ���̽� ����
int M, N, countBaechu, countInsect = 0;
int map[51][51] = { 0 }; //�ʻ���� �ִ� 50�̸� 51���� ������ش�.
int A, B; //��� ������ �����ϱ� ���� A,B
int dx[4] = { 0,0,1,-1 }; // 4�������� ������ �������� �迭
int dy[4] = { 1,-1,0,0 };

//4���⿡ 1�� �ִٸ� �԰� ���ڸ����� �ѹ��� Ȯ���ϴ� �޼ҵ�
void SpreadInsect(int y,int x ){ 
	map[y][x] = 2;
	for (int i = 0; i < 4; i++)
		if (x + dx[i] >= 0 || x + dx[i] < M || y + dy[i] >= 0 || y + dy[i] < N)
			if (map[y + dy[i]][x + dx[i]] == 1)
				SpreadInsect(y + dy[i], x + dx[i]);
}

//���� �迭�� �ʱ�ȭ �����ִ� �޼ҵ�
void initBaechu() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = 0;
}

int main() {
	cin >> testCase;
	while(testCase--) {
		cin >> M >> N >> countBaechu;
		initBaechu();
		for (int i = 0; i < countBaechu; i++) { //���� �����͸� �����Ѵ�.
			cin >> A >> B;
			map[B][A] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) { //���ڸ��� ���߸� �ִٸ�
					countInsect += 1; //���� ���� 1 �ø��� 
					SpreadInsect(i, j); //������ �Ѹ���.
				}
			}
		}
		cout << countInsect << '\n';
		countInsect = 0;
	}
}