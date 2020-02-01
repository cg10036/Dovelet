#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int a, tmp;
	long long cnt = 0;
	stack<int> b, c;
	cin >> a;
	for(int i = 0;i < a;i++)
	{
		cin >> tmp;
		while(b.size() && b.top() <= tmp)
		{
			b.pop();
			cnt += i - c.top() - 1;
			c.pop();
		}
		b.push(tmp);
		c.push(i);
	}
	while(b.size())
	{
		b.pop();
		cnt += a - c.top() - 1;
		c.pop();
	}
	cout << cnt;
}
