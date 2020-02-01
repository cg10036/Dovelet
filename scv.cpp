#include <iostream>
#include <algorithm>

using namespace std;

int dp_data[101][101] = { 0 };
int map[101][101] = { 0 };
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	dp_data[1][1] = map[1][1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dp_data[i][j])
			{
				continue;
			}
			dp_data[i][j] = max(i > 1 ? dp_data[i - 1][j] + map[i][j] : 0, j > 1 ? dp_data[i][j - 1] + map[i][j] : 0);
		}
	}
	cout << dp_data[N][N];
}
