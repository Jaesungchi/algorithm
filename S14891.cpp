#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/14891

typedef struct Topni {
	int number[8] = {0,0,0,0,0,0,0,0};
} Topni;

void TurnLeft() {

}

int main() {
	Topni *first = {};
	for (int j = 0; j < 1; j++) {
		for (int i = 0; i < 8; i++) {
			cin >> first->number[i];
		}
	}
	for (int j = 0; j < 1; j++) {
		for (int i = 0; i < 8; i++) {
			cout << first->number[i];
		}
		cout << '\n';
	}
}