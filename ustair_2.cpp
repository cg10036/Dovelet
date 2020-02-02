#include <iostream>
#include <algorithm>

using namespace std;

int score[301];
int dp_data[301][2];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}
	dp_data[1][0] = score[1];
	dp_data[2][0] = score[1] + score[2];
	dp_data[2][1] = score[2];
	for (int i = 3; i <= N; i++)
	{
		dp_data[i][0] = dp_data[i - 1][1] + score[i];
		dp_data[i][1] = max(dp_data[i - 2][0], dp_data[i - 2][1]) + score[i];
	}
	cout << max(dp_data[N][0], dp_data[N][1]);
}
