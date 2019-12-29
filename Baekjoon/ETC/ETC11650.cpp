#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/11650 ��ǥ �����ϱ�
//���͵� sort ���� �׷��� �ϳ� ���ǽ��� ���� �� ���� � ������ ��Ʈ�� ������ �ε�.
//�ſ� �߿��� ��Ʈ.

int N;

struct Point {
	int x;
	int y;
};

//������ �־��ش�. ����Ʈ�� ����Ʈ�� ���ϴ�
bool cmp(Point &u, Point &v) {
	if (u.x < v.x) return true;
	else if (u.x == v.x)
		return u.y < v.y;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector <Point> datas(N); //����ü�� ���� ������ ���� �� ����.
	for (int i = 0; i < N; i++)
		cin >> datas[i].x >> datas[i].y;

	sort(datas.begin(), datas.end(),cmp); //��Ʈ�Լ� �ſ� �߿�.

	for (int i = 0; i < N; i++)
		cout << datas[i].x<< " " << datas[i].y << "\n";
}