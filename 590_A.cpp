

//n개의 상품, i번째 좋은 가격은 ai
//n가지 상품에 동일한 가격
//손해 보기 싫어 새로운 가격이 초기가격보다 작으면 안됨.
//n개의 상품을 팔때 모두 새가격이 돈을 더 받음.
//하지만 최소한 하나를 선택
//하나는 동등한 가격을 받음.
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
		if (temp >= 0) //0보다 큰 양수이면서
			if (min > temp) { //값차이가 작다면.
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