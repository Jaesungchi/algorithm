#include <string>
#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10820 문자열분석
//문자열을 한번에 받는 방법을 알았다.

string temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int j = 0 ; j < 100 ; j++){
		getline(cin, temp);
		if (temp.length() == 0)
			break;
		int so = 0, dae=0, num=0, space=0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] >= 'a' && temp[i] <= 'z')
				so++;
			else if (temp[i] >= 'A' && temp[i] <= 'Z')
				dae++;
			else if (temp[i] >= '0' && temp[i] <= '9')
				num++;
			else if (temp[i] == ' ')
				space++;
		}
		cout << so << " " << dae << " " << num << " " << space << "\n";
	}
}