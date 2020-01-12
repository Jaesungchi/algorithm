#include <iostream>
#include <queue>
using namespace std;

//[�Ҽ� ���](https://www.acmicpc.net/problem/1963)

bool sosu[10000]; //�Ҽ����� �̸� �����صα� ���� ����
int zisu[4] = { 1000,100,10,1 }; //10�� ������ ��Ƶ�.

int N, M;

typedef struct sc { //ī��Ʈ�� ���ڸ� �����ϱ� ���� ����ü
	int score;
	int counts;
}S;

//�ѱ��ڸ� �ٲ���� Ȯ���ϴ� �Լ�
bool isOneChange(int n, int m) {
	int tmp1 = n, tmp2 = m;
	for(int i = 0 ; i < 4; i++){
		if (abs(tmp1 - tmp2) % zisu[i] == 0) //���ڸ� ���� �������� ���ٸ� Ʈ��
			return true;
		else if (tmp1 / zisu[i] != tmp2 / zisu[i]) //���ڸ��� �ٸ��ٸ� false
			return false;
		tmp1 %= zisu[i];
		tmp2 %= zisu[i];
	}
}

//���� ������ �ذ��ϴ� �Լ�
void run() {
	bool checks[10000] = { false , }; //�鷶���� �ȵ鷶���� Ȯ���ϴ� ����
	cin >> N >> M;
	queue<S> q;
	S tt = { N, 0 };
	q.push(tt);
	checks[N] = true;
	while (q.front().score != M) { //���� ���ڰ� ������ ����
		S temp = q.front();
		q.pop();
		for (int i = 1001; i < 9999; i++) {
			if (!sosu[i] || checks[i]) continue;
			if (isOneChange(temp.score, i)) { //���ڸ��� �ٲ۰Ŷ��
				checks[i] = true;
				S tmp = { i,temp.counts + 1 };
				q.push(tmp);
			}
		}
		if (q.empty()) { //����ٸ� ���̻� ���� ���ٴ� ��.
			cout << "Impossible" << "\n";
			return;
		}
	}
	cout << q.front().counts << "\n";
}

//1~9999������ �Ҽ��� �̸� ����صδ� �Լ�
void checkSosu() {
	int counts;
	sosu[1] = true;
	sosu[2] = true;
	for (int i = 3; i < 10000; i++) {
		counts = 0;
		for (int j = 1; j <= i; j++)
			if (i%j == 0)
				counts++;
		if (counts <= 2)
			sosu[i] = true;
	}
}

int main() {
	int tmp;
	cin >> tmp;
	checkSosu();
	for (int i = 0; i < tmp; i++)
		run();
}