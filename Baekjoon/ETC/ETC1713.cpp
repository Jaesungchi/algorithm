#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[후보 추천하기](https://www.acmicpc.net/problem/1713)

int n;
vector<pair<int,int>> arr;
int t;

int main() {
	int tmp;
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		//이미 등록되어 있는경우
		if (arr.size() > 0) {
			bool flag = false;
			for (int i = 0; i < arr.size(); i++) {
				if (tmp == arr[i].first) {
					arr[i].second++;
					flag = true;
				}
			}
			if (flag)
				continue;
		}
		if (arr.size() >= n) {
			int smallIndex = -1;
			int smallCount = 987654321;
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i].second < smallCount) {
					smallIndex = i;
					smallCount = arr[i].second;
				}
			}
			arr.erase(arr.begin() + smallIndex);
		}
		arr.push_back(make_pair(tmp, 0));
	}
	sort(arr.begin(), arr.end());
	for(int i = 0 ; i < arr.size(); i++)
		cout << arr[i].first << " ";
}