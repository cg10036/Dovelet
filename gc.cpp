#include <iostream>
#include <algorithm>

using namespace std;

int dp_data[20] = { 0 };

int main()
{
	int N;
	cin >> N;
	dp_data[0] = 1;
	dp_data[1] = 1;
	dp_data[2] = 2;
	dp_data[3] = 5;
	for (int i = 4; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp_data[i] += dp_data[j] * dp_data[i - j - 1];
		}
	}
	cout << dp_data[N];
}
