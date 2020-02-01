#include <iostream>

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

void output(int now)
{
	if (tree[now] == -1)
	{
		return;
	}
	output(now * 2);
	output(now * 2 + 1);
	cout << tree[now] << " ";
}

int main()
{
	input(1);
	output(1);
}
