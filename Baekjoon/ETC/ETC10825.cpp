#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10825 ������
//sort,vector �Ƴ� ;; �㹫�ϳ� ;;

struct Point {
	string name;
	int x; //��
	int y; //��
	int z; //��
};

bool sortCheck(const Point &u,const Point &v) {
	if (u.x != v.x) return u.x > v.x; //�������� ���� ��
	if (u.y != v.y) return u.y < v.y; //����� ���� ��
	if (u.z != v.z) return u.z > v.z; //���������� ���� ��
	return u.name < v.name;//�̸� ���� ������.
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <Point> datas(n);
	for (int i = 0; i < n; i++)
		cin >> datas[i].name >> datas[i].x >> datas[i].y >> datas[i].z;

	sort(datas.begin(), datas.end(),sortCheck);

	for (int i = 0; i < n; i++)
		cout << datas[i].name << "\n";
}