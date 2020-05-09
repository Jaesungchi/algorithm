#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };

int LY = 3, LX = 0; //*에서 시작
int RY = 3, RX = 2; //#에서 시작

char centerInput(int num, string hand) {
	int tY, tX = 1;
	switch (num) {
	case 2:
		tY = 0;
		break;
	case 5:
		tY = 1;
		break;
	case 8:
		tY = 2;
		break;
	case 0:
		tY = 3;
		break;
	default:
		break;
	}
	int rDis = abs(tY - RY) + abs(tX - RX);
	int lDis = abs(tY-LY) + abs(tX -LX);
	if (rDis > lDis) {
		LY = tY;
		LX = tX;
		return 'L';
	}
	else if (lDis > rDis) {
		RY = tY;
		RX = tX;
		return 'R';
	}
	else {
		if (!hand.compare("right")) {
			RY = tY;
			RX = tX;
			return 'R';
		}
		else {
			LY = tY;
			LX = tX;
			return 'L';
		}
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	//순환한다.
	for (int i = 0; i < numbers.size(); i++) {
		switch (numbers[i]) {
		case 1:
			answer += 'L';
			LY = 0;
			LX = 0;
			break;
		case 4:
			answer += 'L';
			LY = 1;
			LX = 0;
			break;
		case 7:
			answer += 'L';
			LY = 2;
			LX = 0;
			break;
		case 3:
			answer += 'R';
			RY = 0;
			RX = 2;
			break;
		case 6:
			answer += 'R';
			RY = 1;
			RX = 2;
			break;
		case 9:
			answer += 'R';
			RY = 2;
			RX = 2;
			break;
		default:
			answer += centerInput(numbers[i], hand);
			break;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(9);
	arr.push_back(5);
	solution(arr, "right");
}