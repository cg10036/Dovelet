#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[101];
int list[101] = { 0 };

int main()
{
	int a, b, num;
	queue<int> q1;
	vector<int> result;
	cin >> num;
	while (cin >> a >> b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
		list[b]++;
	}
	for (int i = 1; i <= num; i++)
	{
		if (!list[i])
		{
			q1.push(i);
			list[i]--;
		}
	}
	while (!q1.empty())
	{
		result.push_back(q1.front());
		for (int i = 0; i < adj[q1.front()].size(); i++)
		{
			list[adj[q1.front()][i]]--;
		}
		for (int i = 1; i <= num; i++)
		{
			if (!list[i])
			{
				q1.push(i);
				list[i]--;
			}
		}
		q1.pop();
	}
	if (result.size() != num)
	{
		cout << "impossible";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
	}
}
