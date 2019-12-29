#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://www.acmicpc.net/problem/11652 카드
//예외를 잘 읽어보자 자꾸 예제만 맞다고 코드 넣지 말고

long long int n, temp, counts = 0;
bool isIn = false;

struct p {
	long long int number;
	long count;
};

bool sorts(p &u, p &v) {
	if(u.count != v.count) return u.count > v.count;
	return u.number < v.number;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	vector <p> datas(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		isIn = false;
		for (int j = 0; j < counts; j++) {
			if (temp == datas[j].number) {
				datas[j].count++;
				isIn = true;
				break;
			}
		}
		if (!isIn) {
			datas[counts].number = temp;
			datas[counts].count++;
			counts++;
		}
	}
	sort(datas.begin(),datas.end(),sorts);

	cout << datas[0].number << "\n";
}