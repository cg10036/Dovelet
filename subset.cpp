#include <iostream>

using namespace std;

int dp[40][780] = { 0 }; // 1~i, j를 만드는 방법의 수
int sum[40] = { 0 };

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sum[i] = sum[i - 1] + i;
	}
	if (sum[N] % 2)
	{
		cout << "0";
		return 0;
	}
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= sum[i]; j++)
		{
			if (j - i < 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - i] + dp[i - 1][j];
			}
		}
	}
	cout << dp[N][sum[N] / 2];
}
