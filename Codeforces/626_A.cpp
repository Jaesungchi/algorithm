#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
You are given an array a consisting of n positive integers.
Find a non-empty subset of its elements such that their sum is even (i.e. divisible by 2)
or determine that there is no such subset.
Both the given array and required subset may contain equal values.

Input
The first line contains a single integer t (1≤t≤100),
number of test cases to solve. Descriptions of t test cases follow.

A description of each test case consists of two lines.
The first line contains a single integer n (1≤n≤100), length of array a.

The second line contains n integers a1,a2,an (1≤ai≤100), elements of a.
The given array a can contain equal values (duplicates).

Output
For each test case output −1 if there is no such subset of elements.
Otherwise output positive integer k, number of elements in the required subset.
Then output k distinct integers (1≤pi≤n), indexes of the chosen elements.
If there are multiple solutions output any of them.
*/

void run() {
	int n;
	vector<int> input;
	vector<int> output;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
		if (tmp % 2 == 0)
			output.push_back(i + 1);
	}
	if (input.size() % 2 == 0) {
		cout << input.size() <<
			"\n";
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << "\n";
		return ;
	}

	if (output.size() > 0) {
		cout << output.size() << "\n";
		for (int i = 0; i < output.size(); i++)
			cout << output[i] << " ";
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		run();
}