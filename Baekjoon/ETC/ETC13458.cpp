#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/13458
//�ð����� 2�ʿ� �����Ұ�. O(N^2)�� �Ǹ� �ð��ʰ��� �ȵ�.
int room, master, bojo;
long long m_count = 0; //int�δ� ������ �� ������. longlong ���� �� ����
int member[1000001];

int main() {
	cin >> room;
	for (int i = 0; i < room; i++)
		cin >> member[i];
	cin >> master >> bojo;
	for (int i = 0; i < room; i++) { //���� ������ŭ ����.
		m_count += 1;// �Ѱ������� �������Ѹ� �����Ѵ�.
		member[i] = member[i] - master; //�����ʹ� �ٷ� �Ѹ� ���ش�.
		if (member[i] <= 0) //������ �Ѹ����� ����Ѱ��
			continue;
		m_count += member[i] / bojo; //������ ���� ���� ����̹Ƿ� �������� �ִٸ� �Ѹ�� �߰�
		if (member[i] % bojo > 0)
			m_count += 1;
	}
	cout << m_count;
}