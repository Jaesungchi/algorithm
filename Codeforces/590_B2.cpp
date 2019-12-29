#include <iostream>
using namespace std;

int n, goodSet, temp, sizes = 0,index = 0;
long arr[200201];

//대화를 k번 보여줄 수 있다. 처음은 0
//n개의 메세지를 받으면 i번째 메세지는 ID에게 받는다는걸 알게 된다.

void insert(int ins) {
	for (int i = index; i >= index-sizes; i--) {
		if (arr[i] == ins) //같은게 있다면 아웃.
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