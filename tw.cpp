#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int a, tmp;
	cin >> a;
	stack<int> c, d;
	for(int i = 0;i < a;i++)
	{
		cin >> tmp;
		while(c.size() && c.top() < tmp)
		{
			c.pop();
			d.pop();
		}
		if(!c.size())
		{
			c.push(tmp);
			d.push(i + 1);
			cout << "0 ";
		}
		else
		{
			cout << to_string(d.top()) + " ";
			c.push(tmp);
			d.push(i + 1);
		}
	}
}
