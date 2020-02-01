#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int isPrime(int a)
{
	if (a == 1)
	{
		return 0;
	}
	int cnt = 0, tmp = (int)sqrt(a);
	for (int i = 1; i <= tmp; i++)
	{
		if (a % i == 0)
		{
			cnt++;
		}
	}
	if (cnt == 1)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int a, b;
	queue<int> c, d;
	char e[10000] = { 0 };
	cin >> a >> b;
	c.push(a);
	d.push(0);
	while (c.front() != b)
	{
		int tmp1[4], tmp2;
		tmp1[0] = c.front() / 10 * 10;
		tmp1[1] = c.front() / 100 * 100 + c.front() % 10;
		tmp1[2] = c.front() / 1000 * 1000 + c.front() % 100;
		tmp1[3] = c.front() % 1000;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 3 && j == 0)
				{
					continue;
				}
				tmp2 = tmp1[i] + j * (int)pow(10, i);
				if (isPrime(tmp2) && !e[tmp2])
				{
					e[tmp2] = 1;
					c.push(tmp2);
					d.push(d.front() + 1);
				}
			}
		}
		c.pop();
		d.pop();
	}
	cout << d.front();
}
