#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/5373 Å¥ºù

char datas[6][3][3];
int n, temp, dm[4] = { 0,2,2,0 }, dn[4] = { 0,0,2,2 };
char temp1[2];

void RotateClock(int number) {
	int m_temp = datas[number][0][0],tempC[3];
	for (int i = 0; i < 3; i++)
		datas[number][dm[i]][dn[i]] = datas[number][dm[i + 1]][dn[i + 1]];
	datas[number][0][2] = m_temp;
	m_temp = datas[number][0][1];
	datas[number][0][1] = datas[number][1][0];
	datas[number][1][0] = datas[number][2][1];
	datas[number][2][1] = datas[number][1][2];
	datas[number][1][2] = m_temp;

	if (number == 0) {
		tempC[0] = datas[3][0][0];
		tempC[1] = datas[3][0][1];
		tempC[2] = datas[3][0][2];
		datas[3][0][0] = datas[4][0][0];
		datas[3][0][1] = datas[4][0][1];
		datas[3][0][2] = datas[4][0][2];
		datas[4][0][0] = datas[1][0][0];
		datas[4][0][1] = datas[1][0][1];
		datas[4][0][2] = datas[1][0][2];
		datas[1][0][0] = datas[2][0][0];
		datas[1][0][1] = datas[2][0][1];
		datas[1][0][2] = datas[2][0][2];
		datas[2][0][0] = tempC[0];
		datas[2][0][1] = tempC[1];
		datas[2][0][2] = tempC[2];
	}
	else if (number == 1) {
		tempC[0] = datas[0][2][0];
		tempC[1] = datas[0][2][1];
		tempC[2] = datas[0][2][2];
		datas[0][2][0] = datas[4][2][2];
		datas[0][2][1] = datas[4][1][2];
		datas[0][2][2] = datas[4][0][2];
		datas[4][2][2] = datas[5][2][2];
		datas[4][1][2] = datas[5][2][1];
		datas[4][0][2] = datas[5][2][0];
		datas[5][2][2] = datas[2][0][0];
		datas[5][2][1] = datas[2][1][0];
		datas[5][2][0] = datas[2][2][0];
		datas[2][0][0] = tempC[0];
		datas[2][1][0] = tempC[1];
		datas[2][2][0] = tempC[2];
	}
	else if (number == 2) {
		tempC[0] = datas[0][2][2];
		tempC[1] = datas[0][1][2];
		tempC[2] = datas[0][0][2];
		datas[0][2][2] = datas[1][2][2];
		datas[0][1][2] = datas[1][1][2];
		datas[0][0][2] = datas[1][0][2];
		datas[1][2][2] = datas[5][0][2];
		datas[1][1][2] = datas[5][1][2];
		datas[1][0][2] = datas[5][2][2];
		datas[5][0][2] = datas[3][0][0];
		datas[5][1][2] = datas[3][1][0];
		datas[5][2][2] = datas[3][2][0];
		datas[3][0][0] = tempC[0];
		datas[3][1][0] = tempC[1];
		datas[3][2][0] = tempC[2];
	}
	else if (number == 3) {
		tempC[0] = datas[0][0][0];
		tempC[1] = datas[0][0][1];
		tempC[2] = datas[0][0][2];
		datas[0][0][0] = datas[2][0][2];
		datas[0][0][1] = datas[2][1][2];
		datas[0][0][2] = datas[2][2][2];
		datas[2][0][2] = datas[5][0][2];
		datas[2][1][2] = datas[5][0][1];
		datas[2][2][2] = datas[5][0][0];
		datas[5][0][2] = datas[4][0][0];
		datas[5][0][1] = datas[4][1][0];
		datas[5][0][0] = datas[4][2][0];
		datas[4][0][0] = tempC[2];
		datas[4][1][0] = tempC[1];
		datas[4][2][0] = tempC[0];
	}
	else if (number == 4) {
		tempC[0] = datas[0][0][0];
		tempC[1] = datas[0][1][0];
		tempC[2] = datas[0][2][0];
		datas[0][0][0] = datas[3][2][2];
		datas[0][1][0] = datas[3][1][2];
		datas[0][2][0] = datas[3][0][2];
		datas[3][2][2] = datas[5][2][0];
		datas[3][1][2] = datas[5][1][0];
		datas[3][0][2] = datas[5][0][0];
		datas[5][2][0] = datas[1][0][0];
		datas[5][1][0] = datas[1][1][0];
		datas[5][0][0] = datas[1][2][0];
		datas[1][0][0] = tempC[0];
		datas[1][1][0] = tempC[1];
		datas[1][2][0] = tempC[2];
	}
	else {
		tempC[0] = datas[3][2][0];
		tempC[1] = datas[3][2][1];
		tempC[2] = datas[3][2][2];
		datas[3][2][0] = datas[2][2][0];
		datas[3][2][1] = datas[2][2][1];
		datas[3][2][2] = datas[2][2][2];
		datas[2][2][0] = datas[1][2][0];
		datas[2][2][1] = datas[1][2][1];
		datas[2][2][2] = datas[1][2][2];
		datas[1][2][0] = datas[4][2][0];
		datas[1][2][1] = datas[4][2][1];
		datas[1][2][2] = datas[4][2][2];
		datas[4][2][0] = tempC[0];
		datas[4][2][1] = tempC[1];
		datas[4][2][2] = tempC[2];
	}
}

void PrintALL() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << datas[0][i][j];
		cout << "\n";
	}
	for (int j = 0; j < 3; j++) {
		for (int z = 1; z < 5; z++) {
			for (int i = 0; i < 3; i++)
				cout << datas[z][j][i];
			cout << " ";
		}
		cout << "\n";
	}
	for (int i = 2; i >=0; i--) {
		for (int j = 0; j <3 ; j++)
			cout << datas[5][i][j];
		cout << "\n";
	}
	cout << "\n";
}

void PrintTop() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << datas[0][i][j];
		cout << "\n";
	}
}

void ResetCube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			datas[0][i][j] = 'w';
			datas[1][i][j] = 'r';
			datas[2][i][j] = 'b';
			datas[3][i][j] = 'o';
			datas[4][i][j] = 'g';
			datas[5][i][j] = 'y';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ResetCube();
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> temp1;
			switch (temp1[0]) {
			case 'U':
				if (temp1[1] == '+')
					RotateClock(0);
				else {
					RotateClock(0); RotateClock(0); RotateClock(0);
				}
				break;
			case 'D':
				if (temp1[1] == '+')
					RotateClock(5);
				else {
					RotateClock(5); RotateClock(5); RotateClock(5);
				}
				break;
			case 'F':
				if (temp1[1] == '+')
					RotateClock(1);
				else{
					RotateClock(1); RotateClock(1); RotateClock(1);
				}
				break;
			case 'B':
				if (temp1[1] == '+')
					RotateClock(3);
				else {
					RotateClock(3); RotateClock(3); RotateClock(3);
				}
				break;
			case 'L':
				if (temp1[1] == '+')
					RotateClock(4);
				else {
					RotateClock(4); RotateClock(4); RotateClock(4);
				}
				break;
			case 'R':
				if (temp1[1] == '+')
					RotateClock(2);
				else {
					RotateClock(2); RotateClock(2); RotateClock(2);
				}
				break;
			}
			//PrintALL();
		}
		PrintTop();
	}
}