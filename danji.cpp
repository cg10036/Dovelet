#include <iostream>
#include <algorithm>

using namespace std;

int num;
int map[26][26] = { 0 };
int visit[26][26] = { 0 };
int _array[25 * 25] = { 0 };

int dfs(int i, int j)
{
	int cnt = 1;
	visit[i][j] = 1;
	if (i - 1 >= 0 && map[i - 1][j] && !visit[i - 1][j])
	{
		cnt += dfs(i - 1, j);
	}
	if (j - 1 >= 0 && map[i][j - 1] && !visit[i][j - 1])
	{
		cnt += dfs(i, j - 1);
	}
	if (i + 1 <= num && map[i + 1][j] && !visit[i + 1][j])
	{
		cnt += dfs(i + 1, j);
	}
	if (j + 1 <= num && map[i][j + 1] && !visit[i][j + 1])
	{
		cnt += dfs(i, j + 1);
	}
	return cnt;
}

int main()
{
	int cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				_array[cnt++] = dfs(i, j);
			}
		}
	}
	sort(_array, _array + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << _array[i] << endl;
	}
}
