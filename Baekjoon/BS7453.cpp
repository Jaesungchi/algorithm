#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

//[합이 0인 네정수 난이도 ★★★](https://www.acmicpc.net/problem/7453)

int n;
ll result;
int arr[4][4000], arrAB[4000*4000], arrCD[4000*4000];

void run(){
	int Idx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			arrAB[Idx] = arr[0][i] + arr[1][j];
			arrCD[Idx] = arr[2][i] + arr[3][j];
			Idx++;
		}

	sort(arrAB, arrAB + Idx);
	sort(arrCD, arrCD + Idx);

	int AB_Idx = 0; 
	int CD_Idx = Idx - 1;
	//한쪽이라도 끝나면 종료
	while (AB_Idx < Idx && CD_Idx >= 0) {
		if (arrAB[AB_Idx] + arrCD[CD_Idx] == 0){
			int Orig = AB_Idx;
			ll Same_AB = 0, Same_CD = 0;
			//A에서 현재 원소와 같은 원소의 갯수를 Count한다.
			while (arrAB[AB_Idx] + arrCD[CD_Idx] == 0){
				if (AB_Idx >= Idx) 
					break;
				Same_AB++;
				AB_Idx++;
			}

			while (arrAB[Orig] + arrCD[CD_Idx] == 0){
				if (CD_Idx < 0) 
					break;
				Same_CD++;
				CD_Idx--;
			}

			result = result + (Same_AB * Same_CD); 
		}
		else if (arrAB[AB_Idx] + arrCD[CD_Idx] < 0) 
			AB_Idx++;
		else 
			CD_Idx--;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];
	run();
	cout << result << endl;
}