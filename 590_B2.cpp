#include <iostream>
using namespace std;

int n, goodSet, temp, sizes = 0,index = 0;
long arr[200201];

//��ȭ�� k�� ������ �� �ִ�. ó���� 0
//n���� �޼����� ������ i��° �޼����� ID���� �޴´ٴ°� �˰� �ȴ�.

void insert(int ins) {
	for (int i = index; i >= index-sizes; i--) {
		if (arr[i] == ins) //������ �ִٸ� �ƿ�.
			return;
	}
	arr[index++] = ins;
	if (sizes < goodSet)
		sizes++;
}

int main() {
	cin >> n >> goodSet;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		insert(temp);
	}
	cout << sizes << "\n";
	for (int i = index-1; i >= index - sizes; i--) {
		cout << arr[i] << " ";
	}
}