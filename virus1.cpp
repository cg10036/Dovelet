#include <iostream>

using namespace std;

int adj[102][102] = { 0 };
int visit[102] = { 0 };
int num;

int dfs(int now)
{
	int cnt = 1;
	visit[now] = 1;
	for (int i = 1; i <= num; i++)
	{
		if (adj[now][i] && !visit[i])
		{
			cnt += dfs(i);
		}
	}
	return cnt;
}

int main()
{
	int a;
	cin >> num >> a;
	for (int i = 0; i < a; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1][tmp2] = 1;
		adj[tmp2][tmp1] = 1;
	}
	int ret = dfs(1);
	cout << ret - 1;
}
