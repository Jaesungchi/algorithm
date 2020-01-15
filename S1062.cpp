#include <iostream>
#include <string>
using namespace std;

//[가르침 난이도 ★★★](https://www.acmicpc.net/problem/1062)

int N, K; //N개의 단어 존재, K개 글자 교육.
int maxs = 0; //읽을 수 있는 단어의 최대 갯수
string learn[51]; //배운 단어.
bool alpha[27]; //읽을 수 있는 글자

//읽을 수 있으면 true 없으면 false
bool isReading(string data) {
	for (int i = 0; i < data.length(); i++) {
		int index = data[i] - 'a';
		if (!alpha[index]) //읽을 수 없는 글자라면
			return false;
	}
	return true;
}

//기본 글자이면 넘어감.
bool isBasicAlpha(int i) {
	if (i == 'c' - 'a') return true;
	if (i == 'n' - 'a') return true;
	if (i == 't' - 'a') return true;
	if (i == 'i' - 'a') return true;
	return false;
}

//indexs는 가르친 마지막 글자 다음 글자.
//count는 가르친 글자 갯수
void DFS(int indexs, int count) {
	if (count == K) { //갯수 만큼 교육이 끝났다면
		int t_max = 0;
		for (int i = 0; i < N; i++)
			if (isReading(learn[i]))
				t_max++;
		maxs = t_max > maxs ? t_max : maxs;
		return;
	}
	for (int i = indexs; i < 26; i++) {
		if (isBasicAlpha(i))
			continue;
		alpha[i] = true;
		DFS(i + 1, count + 1);
		alpha[i] = false;
	}
}

//기본적으로 사용하는 글자는 true
void checkBasicWord() {
	alpha[0] = true; //a
	alpha['n' - 'a'] = true; //n
	alpha['t' - 'a'] = true; //t
	alpha['i' - 'a'] = true; //i
	alpha['c' - 'a'] = true; //c
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> learn[i];
	if (K < 5) { //읽을 수 있는 글자가 너무 적으면 종료
		cout << 0 << "\n";
		return 0;
	}
	checkBasicWord();
	DFS(1, 5); //a는 기본글자 임으로 다음 글자부터 체크. 기본 5글자 count
	cout << maxs << "\n";
}