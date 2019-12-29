#include <iostream>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/15685 �巡��Ŀ��
//��û�ϰ� �������� ���� �Ǵ°� ���� �� ���� �ȴ� ������ ;;
//�巡��Ŀ�� ��Ģ�� �ᰡ�鼭 �ϴϱ� �ݹ� ����

int N, A, B, C, D, sums = 0;
bool map[101][101];
vector<int> dir;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C >> D;
		dir.push_back(C);
		for (int i = 0; i < D; i++) //���븸ŭ ���Ѵ�.
			for (int j = dir.size() - 1; j >= 0; j--) // ex)2����� 1������ �� �ں��� +1 ������ +1 �Ȱ�
				dir.push_back((dir[j] + 1) % 4);
		map[B][A] = true;
		for (int i = 0; i < dir.size(); i++) {
			switch (dir[i]) {
			case 0:
				A++;
				break;
			case 1:
				B--;
				break;
			case 2:
				A--;
				break;
			case 3:
				B++;
				break;
			}
			map[B][A] = true;
		}
		dir.clear();
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				sums++;
	cout << sums;
}