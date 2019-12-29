#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14503 �κ�û�ұ�
//������������ count�� �߰��ϰ� �־��� �Ƴ� ;;

int N, M, map[51][51], dx[4] = { 0,1,0,-1 }, dy[4] = {-1,0,1,0},countClear = 0;
int mpX, mpY, mpD; //�κ��� ��ġ �� ����
//0 �� �� ,1�� ��, 2�� ��, 3�� ��

void MoveRobot(int x, int y,int dir) {
	map[y][x] = 8; //û��

	//���� ���⿡ ���� û������ ���� ������ �ִٸ� �׹������� ȸ���� ���� ����
	//���ʿ� û���Ұ����� ���ٸ� �������� ȸ��
	for (int i = 0; i < 4; i++) {
		dir = (dir + 3) % 4; // -1�ѰŶ� ����.
		int mx = x + dx[dir];
		int my = y + dy[dir];
		if (map[my][mx] == 0) { //���̶��
			countClear++;
			MoveRobot(mx, my, dir);
			return;
		}
	}
	//�׹��� ���� û�� ���ְų� ���ΰ�� �ڷ� 1ĭ
	int mx = x + dx[(dir + 2) % 4]; //�ڷ� ��ĭ
	int my = y + dy[(dir + 2) % 4]; //�ڷ� ��ĭ
	//�׹��� ��� û�ҵ��ִµ� �ڵ� ���ΰ�� �۵� ����.
	if (map[my][mx] == 1) // ���̶��
		return; //�����Ѵ�.
	MoveRobot(mx, my, dir);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> mpY >> mpX >> mpD;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	countClear++;
	MoveRobot(mpX, mpY, mpD);
	cout << countClear << "\n";
}