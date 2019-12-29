#include <string>
#include <vector>
#include <iostream>
using namespace std;

//k��ŭ ���� ���� ���� ���� ������ ã�Ƽ� �� �� �߿� ���� ū����ŭ ��ȯ.
//kĭ�� ������ �� �ű⼭ ���� ū���� ���� �ٸ��� ���ǳʰԵ�.
int solution(vector<int> stones, int k) {
	int answer = 0, minIndex = 0 , minIndexMax = 9999999;
	for (int i = 0; i < stones.size() - k + 1; i++) { //¡�˴ٸ� ��ȸ
		int nMax = stones[i],nI = i; //���� �޴´�.
		if (nMax > minIndexMax) continue; //ũ�� �ѱ�
		for (int s = i; s < i + k; s++)
			if (nMax < stones[s])
				nMax = stones[s];
		if (nMax < minIndexMax)
			minIndexMax = nMax;
	}
	return minIndexMax;
}

int main() {
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	cout << solution(stones, k);
}