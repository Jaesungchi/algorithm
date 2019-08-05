#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/11651 좌표 정렬하기2
//vector, sort 심화

struct Point {
	int x;
	int y;
};

bool checkdatas(Point &u, Point &v) {
	if (u.y < v.y) return true;
	else if (u.y == v.y)
		return u.x < v.x;
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
	for (int i = 0; i < N; i++)
		cin >> datas[i].x >> datas[i].y;
	sort(datas.begin(), datas.end(), checkdatas);

	for(int i = 0 ; i < N; i++)
		cout << datas[i].x << " " << datas[i].y << "\n";
}