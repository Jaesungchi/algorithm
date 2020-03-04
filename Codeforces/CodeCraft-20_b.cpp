#include <iostream>
#include <string>
using namespace std;

void run() {
	int length;
	string datas;
	cin >> length >> datas;
	int outputIndex = 1;
	string output = datas;
	for (int i = 2; i <= length; i++) { //length 만큼 반복
		string tmp = datas;
		if (tmp[0] < tmp[i - 1]) continue; //애초에 바뀌는자리보다 길면 안함.
		for (int j = 0; j + i <= length; j++) {//i개 길이 만큼 반복
			reverse(tmp.begin() + j, tmp.begin() + j + i);
			if (tmp > output)
				if(tmp.substr(0,j+1) > output.substr(0,j+1))
					break;
		}
		if (tmp < output) {
			output = tmp;
			outputIndex = i;
		}
	}
	cout << output << "\n";
	cout << outputIndex << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
		run();
}