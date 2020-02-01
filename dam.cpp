#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int a, map[100][100] = { 0 }, startx, starty, buildtime;
	int tmp1 = 0, tmp2 = 0;
	queue<int> x, y, time;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> starty >> startx >> buildtime;
	map[startx - 1][starty - 1] = 1;
	x.push(startx - 1);
	y.push(starty - 1);
	time.push(0);
	while (!x.empty())
	{
		if (time.front() == buildtime)
		{
			break;
		}
		if (tmp2 != time.front())
		{
			tmp1 = 0;
			tmp2 = time.front();
		}
		if (x.front() > 0 && !map[x.front() - 1][y.front()])
		{
			x.push(x.front() - 1);
			y.push(y.front());
			time.push(time.front() + 1);
			map[x.front() - 1][y.front()] = 1;
			tmp1++;
		}
		if (x.front() < a - 1 && !map[x.front() + 1][y.front()])
		{
			x.push(x.front() + 1);
			y.push(y.front());
			time.push(time.front() + 1);
			map[x.front() + 1][y.front()] = 1;
			tmp1++;
		}
		if (y.front() > 0 && !map[x.front()][y.front() - 1])
		{
			x.push(x.front());
			y.push(y.front() - 1);
			time.push(time.front() + 1);
			map[x.front()][y.front() - 1] = 1;
			tmp1++;
		}
		if (y.front() < a - 1 && !map[x.front()][y.front() + 1])
		{
			x.push(x.front());
			y.push(y.front() + 1);
			time.push(time.front() + 1);
			map[x.front()][y.front() + 1] = 1;
			tmp1++;
		}
		x.pop();
		y.pop();
		time.pop();
	}
	if (!x.empty())
	{
		cout << tmp1 << endl;
	}
	else
	{
		cout << "OH, MY GOD" << endl;
	}
}
