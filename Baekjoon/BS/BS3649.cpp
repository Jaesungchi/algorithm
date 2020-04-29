#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//[로봇 프로젝트 난이도★★](https://www.acmicpc.net/problem/3649)

int block[1000001];

bool go(int x, int n, int& l1, int& l2) {
	int s = 10000000 * x;
	for (int i = 0; i < n && block[i] < s; i++) {
		l1 = block[i], l2 = s - l1;
		if (binary_search(block + i + 1, block + n, l2)) return true;
	}
	return false;
}
int main() {
	for (int x; scanf("%d", &x) == 1; ) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &block[i]);
		sort(block, block + n);
		int l1, l2;
		if (go(x, n, l1, l2)) printf("yes %d %d\n", l1, l2);
		else printf("danger\n");
	}
	return 0;
}