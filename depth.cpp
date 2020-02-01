#include <iostream>
#include <cmath>

using namespace std;

int tree[100] = { 0 };

void input(int now)
{
	cin >> tree[now];
	if (tree[now] == -1)
	{
		return;
	}
	input(now * 2);
	input(now * 2 + 1);
}

int child(int now)
{
	if (tree[now] == -1)
	{
		return 0;
	}
	if (tree[now * 2] != -1 && tree[now * 2 + 1] != -1)
	{
		return child(now * 2) + child(now * 2 + 1) + 1;
	}
	return child(now * 2) + child(now * 2 + 1);
}

int depth(int now)
{
	if (tree[now] == -1)
	{
		return 0;
	}
	if (depth(now * 2) < depth(now * 2 + 1))
	{
		return depth(now * 2 + 1) + 1;
	}
	return depth(now * 2) + 1;
}

int main()
{
	input(1);
	cout << child(1) << endl;
	cout << depth(1);
}
