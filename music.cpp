#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v[1001];
vector<int> adj[1001];

struct ints
{
	int a;
	int b;
};

int main()
{
	vector<ints> list;
	vector<int> result;
	queue<int> q1;
	int a, b, c, d, e;
	ints tmp;
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;
		for (int j = 1; j < c; j++)
		{
			cin >> e;
			tmp.a = d;
			tmp.b = e;
			list.push_back(tmp);
			d = e;
		}
	}
	for (int i = 0; i < list.size(); i++)
	{
		adj[list[i].a].push_back(list[i].b);
		adj[list[i].b].push_back(list[i].a);
		v[list[i].b]++;
	}
	for (int i = 1; i <= a; i++)
	{
		if (!v[i])
		{
			q1.push(i);
			v[i]--;
		}
	}
	while (!q1.empty())
	{
		result.push_back(q1.front());
		for (int i = 0; i < adj[q1.front()].size(); i++)
		{
			v[adj[q1.front()][i]]--;
		}
		for (int i = 1; i <= a; i++)
		{
			if (!v[i])
			{
				q1.push(i);
				v[i]--;
			}
		}
		q1.pop();
	}
	if (result.size() != a)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}
}
