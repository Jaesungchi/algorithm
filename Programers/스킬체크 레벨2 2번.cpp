#include <iostream>
#include <string>
using namespace std;

//n은 진법 2<= n <= 16
//t는 미리 구할 숫자 0 < t < 1000
//m은 참가인원 2 <= m <= 100
//p는 튜브의 순서 1 <= p <= m

string solution(int n, int t, int m, int p) {
	string answer = "";
	string outputs = "0123456789ABCDEF";
	int realIndex = 0; //실제 10진수로의 값
	string realNum = ""; //현재 숫자
	int jari = 0; //몇번째자리까지 출력했는지 역순으로 
	for (int i = 1; i <= 100000; i++) { //최대턴 10만
		if (answer.length() == t)
			break;
		if (jari >= realNum.length()) { //자리수만큼 숫자가 늘면 index를 늘린다.
			int tmp = realIndex++;
			jari = 0;
			//글자를 만든다.
			realNum = "";
			while (tmp >= n) {
				realNum = outputs[tmp%n] + realNum;
				tmp /= n;
			}
			realNum = outputs[tmp%n] + realNum;
		}
		int turn = i % m == 0 ? m :i%m;
		if (turn == p) { //튜브 차례
			answer += realNum[jari];
		}
		jari++;
	}
	return answer;
}

int main() {
	int n, t, m, p;
	cin >> n >> t >> m >> p;
	cout << solution(n, t, m, p);
}