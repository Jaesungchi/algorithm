#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/* 문제
카카오 프렌즈 컬러링북
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 
여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 
그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.
*/
/* 입력예시
6 4
1 1 1 0
1 2 2 0
1 0 0 1
0 0 0 1
0 0 0 3
0 0 0 3

*/

bool visits[101][101];
int number_of_area = 0;
int max_size_of_one_area = 0;
int dm[4] = { 1,0,-1,0 }, dn[4] = { 0,1,0,-1 };
int max_m = 0, max_n = 0;

void BFS(int m, int n, vector<vector<int>> picture) {
	int sizes = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(m, n));
	visits[m][n] = true;
	while (!q.empty()) {
		int tm = q.front().first;
		int tn = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int sm = tm + dm[i];
			int sn = tn + dn[i];
			if (sm < 0 || sn < 0 || sm >= max_m || sn >= max_n) continue;
			if (picture[sm][sn] != picture[m][n] || visits[sm][sn]) continue;
			visits[sm][sn] = true;
			q.push(make_pair(sm, sn));
			sizes++;
		}
	}
	number_of_area++;
	max_size_of_one_area = max_size_of_one_area < sizes ? sizes : max_size_of_one_area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	max_m = m;
	max_n = n;
	number_of_area = 0;
	max_size_of_one_area = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visits[i][j] = false;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (picture[i][j] != 0 && !visits[i][j])
				BFS(i, j, picture);

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m, n,t;
	vector<vector<int>> p;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		vector<int> q;
		for (int j = 0; j < n; j++) {
			cin >> t;
			q.push_back(t);
		}
		p.push_back(q);
	}
	vector<int> q = solution(m,n,p);
	for (int i = 0; i < q.size(); i++)
		cout << q << " ";
}