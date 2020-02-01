#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int a, b;
	stack<int> c, d;
	cin >> a;
	while(1)
	{
		while(c.size())
		{
			c.pop();
		}
		while(d.size())
		{
			d.pop();
		}
		for(int i = a;i >= 1;i--)
		{
			c.push(i);
		}
		for(int i = 0;i < a;i++)
		{
			cin >> b;
			if(!b)
			{
				goto end;
			}
			while(!d.size() || d.top() != b)
			{
				if(!c.size())
				{
					i++;
					for(;i < a;i++)
					{
						cin >> b;
					}
					goto error;
				}
				d.push(c.top());
				c.pop();
			}
			d.pop();
		}
		cout << "Yes\n";
		continue;
	error:
		cout << "No\n";
	}
end:
	return 0;
}
