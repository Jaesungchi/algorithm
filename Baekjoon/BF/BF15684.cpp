#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/15684 ��ٸ� ����
//�ð��ʰ� ������ �������.

int N, M, H,hap = -1 ;
bool linemap[31][11];

bool sadari() {//��ٸ��� ������.
	for (int i = 1; i < N; i++) { //���μ� ������ŭ ����. �Ǹ������� �ȵ����� �� true�� true
		int pos = i;
		for (int j = 1; j <= H; j++) { //���鼭 ���μ��� �ϳ��� üũ�Ѵ�.
			if (linemap[j][pos]) { //�����ʿ� ���� �ִٸ�
				pos += 1; //��������+1 �ϰ�
				continue;  //��ĭ �Ʒ���
			}
			else if (linemap[j][pos-1]) {//���ʿ� ���� �ִٸ�
				pos -= 1; //������ -1 �ϰ�
				continue;
			}
		}
		if (pos != i) //�������� ���� ������
			return false;
	}
	return true; //�� ���������� ���ٸ�.
}


void Runs(int counts,int y) {
	if (counts > 3) return;
	if (sadari()) {//��ٸ��� �� ���ư��ٸ�
		hap = hap > -1 ? hap > counts ? counts : hap : counts;
		return;
	}
	for (int i = y; i <= H; i++) {
		for (int j = 1; j < N; j++) { //���� -1 �� �����Ƿ�
			if (linemap[i][j]) continue; //�̹� ���� �ִ°��� �н�
			if (linemap[i][j - 1]) continue; //�ٷ� ���ʿ� ���� �־ �н�
			if (linemap[i][j + 1]) continue; //�ٷ� �����ʿ� ���� �־ �н�
			linemap[i][j] = true;
			Runs(counts + 1,i);
			linemap[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> H; //N�� ���μ� H�� ���μ�
	for (int i = 1; i <= M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		linemap[temp1][temp2] = true; //��ٸ��� �ִ°��� true
	}
	Runs(0,1);
	cout << hap << "\n";
}