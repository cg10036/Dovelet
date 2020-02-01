#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int a, b;
	char e[100001] = { 0 };
	queue<int> c, d;
	cin >> a >> b;
	c.push(a);
	d.push(0);
	while(!c.empty())
	{
		if(c.front() == b)
		{
			break;
		}
		if(c.front() - 1 >= 0 && !e[c.front() - 1])
		{
			c.push(c.front() - 1);
			d.push(d.front() + 1);
			e[c.front() - 1] = 1;
		}
		if(c.front() + 1 <= 100000 && !e[c.front() + 1])
		{
			c.push(c.front() + 1);
			d.push(d.front() + 1);
			e[c.front() + 1] = 1;
		}
		if(c.front() * 2 <= 100000 && !e[c.front() * 2])
		{
			c.push(c.front() * 2);
			d.push(d.front() + 1);
			e[c.front() * 2] = 1;
		}
		c.pop();
		d.pop();
	}
	cout << d.front();
}
