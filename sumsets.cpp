#include <iostream>
#include <string>

using namespace std;

int N;
long long a[21][1000001];
int maxi;

long long _pow(long long a, long long b)
{
	long long result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}

int main()
{
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		a[0][i] = 1;
	}
	for (int i = 1; _pow(2, i) <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			a[i][j] = (_pow(2, i) <= j ? a[i][j - _pow(2, i)] + a[i - 1][j] : a[i - 1][j]) % 1000000000;
		}
		maxi = i;
	}
	cout << to_string(a[maxi][N]);
}
