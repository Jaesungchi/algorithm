#include <iostream>
#define MAX(a, b) (((a) > (b))? (a) : (b))
using namespace std;

int main()
{
	int N, T[1500000], P[1500000], m_Max = 0, Mdex, M2 = 0;
	int dp[1500001], dp2[1500001]; //dp는 X일부터 일했을때 얻을 수 있는 최대 값을 저장한다. dp2는  X부터 N일까지의 최대값을 저장한다.
	cin >> N;
	Mdex = N;
	dp[N] = dp2[N] = 0;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	for (int i = N - 1; i >= 0; i--) // N번만큼 돈다. 뒤에서부터 접근
	{
		if (T[i] + i >= N + 1) dp[i] = 0; //일한 시간과 최대일수를 합쳤을때 일자가 넘어가면 그 일자에 일했을때 맥스는 0;
		else
		{
			if (T[i] + i - 1 < Mdex) dp[i] = P[i] + m_Max; //값을 전 위치랑 비교해서 작으면 바로 추가 한다.
			else dp[i] = P[i] + dp2[T[i] + i]; //전위치 것을 추가할 수 없는 경우 이것만 바로 계산해서 저장한다.
		}
		if (m_Max <= dp[i]) m_Max = dp[i], Mdex = i; //dp[i] 가 맥스보다 더크면 바꾼다. 왜냐 ? dp[i] 위에서 if에 들어간거랑 else에 들어간거랑 다름
		M2 = dp2[i] = MAX(M2, dp[i]); //값이 더 큰것을 dp2[i]랑 M2에 저장한다.
	}
	cout << m_Max;
}


