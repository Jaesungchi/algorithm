

//n���� ��ǰ, i��° ���� ������ ai
//n���� ��ǰ�� ������ ����
//���� ���� �Ⱦ� ���ο� ������ �ʱⰡ�ݺ��� ������ �ȵ�.
//n���� ��ǰ�� �ȶ� ��� �������� ���� �� ����.
//������ �ּ��� �ϳ��� ����
//�ϳ��� ������ ������ ����.
#include <iostream>
#include <cmath>
using namespace std;

int q;

void Run() {
	int n,initarr[101],find,min = 999999,save;
	float ab = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> initarr[i];
		ab += initarr[i];
	}
	ab = ab / n;
	find = floor(ab+0.5);
	for (int i = 0; i < n; i++) {
		int temp = initarr[i] - find;
		if (temp >= 0) //0���� ū ����̸鼭
			if (min > temp) { //�����̰� �۴ٸ�.
				save = initarr[i];
				min = temp;
			}
	}
	cout << save <<"\n";

} //Run()

int main() {
	cin >> q;
	for (int i = 0; i < q; i++)
		Run();
}