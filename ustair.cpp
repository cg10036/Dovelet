#include <iostream>
#include <algorithm>

using namespace std;

int score[301] = { 0 };
int dp_data[301] = { 0 };
int st[301] = { 0 };
int N;

int dp(int a)
{
	if (dp_data[a])
	{
		return dp_data[a];
	}
	dp_data[a] = max(dp_data[a - 2] + score[a], dp_data[a - 3] + score[a - 1] + score[a]);
	return dp_data[a]
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}
	dp_data[1] = score[1];
	dp_data[2] = score[1] + score[2];
	dp_data[3] = max(score[1] + score[3], score[2] + score[3]);
	for (int i = 1; i <= N; i++)
	{
		dp(i);
	}
	cout << dp(N);
}
