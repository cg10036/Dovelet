#include <iostream>
#include <climits>

using namespace std;

int visit[21][21] = { 0 };
int map[21][21] = { 0 };
int xmax, ymax;

int dfs(int x, int y, int cnt)
{
	int min = INT_MAX, tmp;
	visit[y][x] = 1;
	if (x == xmax && y == 1)
	{
		visit[y][x] = 0;
		return cnt;
	}
	if (x > 1 && !map[y][x - 1] && !visit[y][x - 1])
	{
		tmp = dfs(x - 1, y, cnt + 1);
		if (tmp < min && tmp)
		{
			min = tmp;
		}
	}
	if (x < xmax && !map[y][x + 1] && !visit[y][x + 1])
	{
		tmp = dfs(x + 1, y, cnt + 1);
		if (tmp < min && tmp)
		{
			min = tmp;
		}
	}
	if (y > 1 && !map[y - 1][x] && !visit[y - 1][x])
	{
		tmp = dfs(x, y - 1, cnt + 1);
		if (tmp < min && tmp)
		{
			min = tmp;
		}
	}
	if (y < ymax && !map[y + 1][x] && !visit[y + 1][x])
	{
		tmp = dfs(x, y + 1, cnt + 1);
		if (tmp < min && tmp)
		{
			min = tmp;
		}
	}
	visit[y][x] = 0;
	if (min == INT_MAX)
	{
		return 0;
	}
	return min;
}

int main()
{
	cin >> ymax >> xmax;
	for (int i = 1; i <= ymax; i++)
	{
		char a[30];
		cin >> a;
		for (int j = 1; j <= xmax; j++)
		{
			map[i][j] = a[j - 1] - '0';
		}
	}
	cout << dfs(1, ymax, 1);
}
