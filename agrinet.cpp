#include <iostream>
#include <queue>

using namespace std;

int list[101][101] = { 0 };
int parents[101] = { 0 };
priority_queue<pair<int, pair<int, int>>> Q;

int _find(int node)
{
	if (!parents[node])
	{
		return node;
	}
	return parents[node] = _find(parents[node]);
}

void _union(int x, int y)
{
	parents[_find(x)] = y;
}

int main()
{
	int N, cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> list[i][j];
			Q.push(make_pair(list[i][j] * -1, make_pair(i, j)));
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		a = Q.top().first;
		b = Q.top().second.first;
		c = Q.top().second.second;
		
		if (_find(b) == _find(c))
		{
			Q.pop();
			i--;
			continue;
		}
		cnt += a;
		_union(b, c);
		Q.pop();
	}
	cout << cnt * -1 << endl;
}
