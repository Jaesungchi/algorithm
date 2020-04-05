#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define INT_MAX = 0x7FFFFFFF

bool compares(string a, string b){
	while (a.length() > 0 && b.length() > 0) {
		string ta = a.substr(0, a.find('/'));
		if (ta.length() < a.length())
			a = a.substr(ta.length() + 1, a.length());
		else
			a = "";
		string tb = b.substr(0, b.find('/'));
		if (tb.length() < b.length())
			b = b.substr(tb.length() + 1, b.length());
		else
			b = "";
		if (ta.compare(tb))
			return ta < tb;
	}
	return a.length() <  b.length();
}

vector<string> solution(vector<string> directory, vector<string> command) {
	vector<string> ::iterator iter;
	for (int i = 0; i < command.size(); i++) {
		string commands = command[i].substr(0, command[i].find(" "));
		string path = command[i].substr(commands.length() + 1, command[i].length());
		string a, b;
		switch (commands[0]) {
		case 'm': //mkdir
			directory.push_back(path);
			break;
		case 'r': //rm
			for (int j = 0; j < directory.size(); j++) {
				if (directory[j].length() < path.length()) //pass the less length
					continue;
				if (!directory[j].substr(0,path.length()).compare(path)) {
					directory.erase(directory.begin() + j);
					j--;
				}
			}
			break;
		case 'c': //cp
			a = path.substr(0, path.find(" "));
			b = path.substr(a.length() + 1, path.length());
			for (int j = 0; j < directory.size(); j++) {
				if (directory[j].length() < a.length()) //pass the less length
					continue;
				if (!directory[j].substr(0, a.length()).compare(a)) {
					string lastword = a.length() - a.find_last_of("/");
					string tmp = directory[j].substr(a.find(path)-lastword.length(), directory[j].length());
					directory.push_back(b + directory[j]);
				}
			}
			break;
		}
	}
	sort(directory.begin(), directory.end(),compares);
	return directory;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> arr;
	//arr.push_back("/");
	//arr.push_back("/hello");
	//arr.push_back("/hello/tmp");
	//arr.push_back("/root");
	//arr.push_back("/root/abcd");
	//arr.push_back("/root/abcd/etc");
	//arr.push_back("/root/abcd/hello");
	arr.push_back("/");
	vector<string> arr2;
	//arr2.push_back("mkdir /root/tmp");
	//arr2.push_back("cp /hello /root/tmp");
	//arr2.push_back("rm /hello");
	arr2.push_back("mkdir /a");
	arr2.push_back("mkdir /a/b");
	arr2.push_back("mkdir /a/b/c");
	arr2.push_back("cp /a/b /");
	arr2.push_back("rmm /a/b/c");


	solution(arr,arr2);
}