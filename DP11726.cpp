#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/11726 2xn Ÿ�ϸ�
//��Ģ�� ã���� �� �� ����.
//���� �Ǵ°��� ���� ����  %�� ��� �������
// A%b + C%b == (A + C)%b �̴�. 

int visit[1001];

int main() {
	int N;
	cin >> N;
	visit[1] = 1;
	visit[2] = 2;
	for (int i = 3; i <= N; i++) {
		visit[i] = visit[i - 1] + visit[i - 2];
		visit[i] %= 10007;
	}
	cout << visit[N];
}