#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num_room, num_door;
vector<int> adj[100001];
int visit[100001] = { 0 };

void dfs(int now)
{
	visit[now] = 1;
	cout << now << " ";
	for (vector<int>::const_iterator i = adj[now].cbegin(); i != adj[now].cend(); i++)
	{
		if (!visit[*i])
		{
			dfs(*i);
		}
	}
}

int main()
{
	int tmp1, tmp2;
	cin >> num_room >> num_door;
	for (int i = 1; i <= num_door; i++)
	{
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= num_room; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(1);
}
