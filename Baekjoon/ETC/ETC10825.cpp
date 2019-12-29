#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10825 국영수
//sort,vector 아놔 ;; 허무하네 ;;

struct Point {
	string name;
	int x; //국
	int y; //영
	int z; //수
};

bool sortCheck(const Point &u,const Point &v) {
	if (u.x != v.x) return u.x > v.x; //국어점수 감소 순
	if (u.y != v.y) return u.y < v.y; //영어는 증가 순
	if (u.z != v.z) return u.z > v.z; //수학점수는 감소 순
	return u.name < v.name;//이름 사전 증가순.
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