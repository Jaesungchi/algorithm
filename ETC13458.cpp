#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/13458
//시간제한 2초에 조심할것. O(N^2)가 되면 시간초과로 안됨.
int room, master, bojo;
long long m_count = 0; //int로는 갯수를 다 못담음. longlong 사용법 꼭 숙지
int member[1000001];

int main() {
	cin >> room;
	for (int i = 0; i < room; i++)
		cin >> member[i];
	cin >> master >> bojo;
	for (int i = 0; i < room; i++) { //룸의 갯수만큼 돈다.
		m_count += 1;// 총감독관은 무조건한명 포함한다.
		member[i] = member[i] - master; //마스터는 바로 한명 빼준다.
		if (member[i] <= 0) //마스터 한명으로 충분한경우
			continue;
		m_count += member[i] / bojo; //음수가 되지 않은 경우이므로 나머지가 있다면 한명더 추가
		if (member[i] % bojo > 0)
			m_count += 1;
	}
	cout << m_count;
}