#include <iostream>
#include <vector>

using namespace std;

int list[10000000] = { 0 };
int dp[1230][1230] = { 0 };
vector<int> prime;

int main()
{
	int N;
	int cnt;
	int input;
	for (int i = 2; i <= 10001; i++)
	{
		cnt = 0;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				cnt++;
				break;
			}
		}
		if (!cnt)
		{
			prime.push_back(i);
		}
	}
	for (int i = 0; i < prime.size(); i++)
	{
		dp[i + 1][0] = dp[i][0] + prime[i];
	}
	for (int i = 1; i <= prime.size(); i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i][0] - dp[j][0];
		}
	}
	for (int i = 1; i < 1230; i++)
	{
		for (int j = 0; j < i; j++)
		{
			list[dp[i][j]]++;
		}
	}
	while (cin >> input && input)
	{
		cout << list[input] << endl;
	}
}
