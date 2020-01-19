#include <iostream>
#include <string>
using namespace std;

//boj.kr/2011 //��ȣ�ڵ�
//�Ƴ� ���ڽ� ��Ģ�� ���� ã�Ҵµ� �ڲ� Ʋ�ȴٰ� ���ͼ� 7�� Ʋ���� ;; ��

const int MAX = 5000 + 1;
const int MOD = 1000000;
int len;
int arr[MAX];
int cache[MAX];

int password(void)
{
	cache[0] = 1; //0
	for (int i = 1; i <= len; i++)
	{
		//A~I�� �����Ͽ��� ���
		if (arr[i] >= 1 && arr[i] <= 9)
			cache[i] = (cache[i - 1] + cache[i]) % MOD;
		if (i == 1)
			continue;
		//J~Z�� �����Ͽ��� ���
		int temp = arr[i] + arr[i - 1] * 10;
		if (10 <= temp && temp <= 26)
			cache[i] = (cache[i - 2] + cache[i]) % MOD;
	}
	return cache[len];
}

int main()
{
	string s;
	cin >> s;
	len = s.length();
	if (len >= MAX)
		exit(-1);
	for (int i = 1; i <= len; i++)
		arr[i] = s[i - 1] - '0';
	if (len == 1 && s[0] == 0) //�߿�
		cout << 0 << endl;
	else
		cout << password() << endl;
	return 0;
}