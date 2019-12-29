#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/11650 좌표 정렬하기
//벡터도 sort 가능 그런데 하나 조건식을 넣을 수 있음 어떤 식으로 소트할 것인지 인듯.
//매우 중요한 파트.

int N;

struct Point {
	int x;
	int y;
};

//조건을 넣어준다. 포인트와 포인트를 비교하는
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
	vector <Point> datas(N); //구조체로 벡터 사이즈 만들 수 있음.
	for (int i = 0; i < N; i++)
		cin >> datas[i].x >> datas[i].y;

	sort(datas.begin(), datas.end(),cmp); //소트함수 매우 중요.

	for (int i = 0; i < N; i++)
		cout << datas[i].x<< " " << datas[i].y << "\n";
}