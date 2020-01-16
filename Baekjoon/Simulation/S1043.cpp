#include <iostream>
using namespace std;

//[거짓말 난이도★★★](https://www.acmicpc.net/problem/1043)

int N, M; //사람 수 N, 파티 수 M
int K; //진실을 아는 사람의 수 K
int C = 0; //과장된 이야기를 한 파티의 수 C
bool member[51]; //진실을 알면 true 모르면 false, 1 부터 시작
bool realParty[51]; //진실을 말하는 파티면 true 아니면 false;
int comeNum[51][51]; //참가자를 저장하는 변수 참가하면 번호를 담는다. 0번에는 참가자 수

//진실을 아는 사람으로 바꾸는 함수.
void turnTrueMember(int index) {
	for (int i = 1; i <= comeNum[index][0]; i++)
		member[comeNum[index][i]] = true;
}

//진실을 전파하는 함수.
bool runParty() {
	bool isKnow = false; //true면 변화가 있었음, false면 없었음
	for (int i = 0; i < M; i++) {
		if (realParty[i]) continue; //진짜 파티면 넘어감 셀 필요가 없음.
		for (int j = 1; j <= comeNum[i][0]; j++) { //순환하면서 진짜 인지 센다.
			if (member[comeNum[i][j]]) {//가짜파티인데 진짜를 알고있는 사람이라면?
				realParty[i] = true; // 진짜로 바꾼다.
				turnTrueMember(i); //맴버들도 진실을 아는 사람으로 바꾼다.
				isKnow = true; //변화를 준다.
			}
		}
	}
	if (!isKnow) //변화가 없었다면
		return true;
	return false;
}

int main() {
	int tmp; //임시변수 tmp
	cin >> N >> M;
	cin >> K;
	//진실을 아는 사람을 받는다.
	for (K; K > 0; K--) {
		cin >> tmp;
		member[tmp] = true;
	}
	//파티를 참가인원을 받는다.
	for (int j = 0; j < M; j++) {
		cin >> comeNum[j][0]; //0번에는 참가자 수를 담는다.
		for (int i = 1; i <= comeNum[j][0]; i++) {
			cin >> tmp;
			comeNum[j][i] = tmp;
			if (member[tmp])
				realParty[j] = true;
		}
		if (realParty[j]) //진짜 파티면 나머지도 true로 바꾼다.
			turnTrueMember(j);
	}
	while (true)//변화가 없을때 까지 반복해서 돈다.
		if (runParty())
			break;
	//가짜 파티의 카운트.
	for (int i = 0; i < M; i++)
		if (!realParty[i])
			C++;
	cout << C << "\n";
}