#include <iostream>
#define MAX(a, b) (((a) > (b))? (a) : (b))
using namespace std;

int main()
{
	int N, T[1500000], P[1500000], m_Max = 0, Mdex, M2 = 0;
	int dp[1500001], dp2[1500001]; //dp�� X�Ϻ��� �������� ���� �� �ִ� �ִ� ���� �����Ѵ�. dp2��  X���� N�ϱ����� �ִ밪�� �����Ѵ�.
	cin >> N;
	Mdex = N;
	dp[N] = dp2[N] = 0;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	for (int i = N - 1; i >= 0; i--) // N����ŭ ����. �ڿ������� ����
	{
		if (T[i] + i >= N + 1) dp[i] = 0; //���� �ð��� �ִ��ϼ��� �������� ���ڰ� �Ѿ�� �� ���ڿ� �������� �ƽ��� 0;
		else
		{
			if (T[i] + i - 1 < Mdex) dp[i] = P[i] + m_Max; //���� �� ��ġ�� ���ؼ� ������ �ٷ� �߰� �Ѵ�.
			else dp[i] = P[i] + dp2[T[i] + i]; //����ġ ���� �߰��� �� ���� ��� �̰͸� �ٷ� ����ؼ� �����Ѵ�.
		}
		if (m_Max <= dp[i]) m_Max = dp[i], Mdex = i; //dp[i] �� �ƽ����� ��ũ�� �ٲ۴�. �ֳ� ? dp[i] ������ if�� ���Ŷ� else�� ���Ŷ� �ٸ�
		M2 = dp2[i] = MAX(M2, dp[i]); //���� �� ū���� dp2[i]�� M2�� �����Ѵ�.
	}
	cout << m_Max;
}


