#include <iostream>
#include <string>

using namespace std;

int N;
long long a[52][52];
int maxi;

int main()
{
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		a[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			a[i][j] = i <= j ? a[i][j - i] + a[i - 1][j] : a[i - 1][j];
		}
	}
	cout << a[N][N];
}
