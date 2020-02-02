#include <iostream>
#include <algorithm>

using namespace std;

int P;
int S[150001] = { 0 };
int dp[150001][2] = { 0 };

int main()
{
	cin >> P;
	for (int i = 1; i <= P; i++)
	{
		cin >> S[i];
	}
	for (int i = 1; i <= P; i++)
	{
		dp[i][0] = max(dp[i - 1][1] + S[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] - S[i], dp[i - 1][1]);
	}
	cout << max(dp[P][0], dp[P][1]);
}
