#include <string>
#include <vector>
#include <iostream>
using namespace std;

//k만큼 수을 따져 제일 작은 범위를 찾아서 그 수 중에 제일 큰수만큼 반환.
//k칸을 따졌을 때 거기서 제일 큰수가 작은 다리를 못건너게됨.
int solution(vector<int> stones, int k) {
	int answer = 0, minIndex = 0 , minIndexMax = 9999999;
	for (int i = 0; i < stones.size() - k + 1; i++) { //징검다리 순회
		int nMax = stones[i],nI = i; //값을 받는다.
		if (nMax > minIndexMax) continue; //크면 넘김
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