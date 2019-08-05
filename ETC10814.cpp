#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//https://www.acmicpc.net/problem/10814 나이순 정렬
//sort,vector 활용

struct Point {
	int age;
	int number;
	string name;
};

bool sortData(Point &u, Point &v) {
	if (u.age < v.age) return true;
	else if (u.age == v.age)
		return u.number < v.number;
	else
		return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector <Point> datas(N);
	for (int i = 0; i < N; i++) {
		cin >> datas[i].age >> datas[i].name;
		datas[i].number = i;
	}

	sort(datas.begin(), datas.end(), sortData);

	for (int i = 0; i < N; i++)
		cout << datas[i].age << " " << datas[i].name << "\n" ;
}