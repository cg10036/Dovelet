#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string a;
	string b = "";
	stack<char> c;
	stack<char> d;
	cin >> a;
	for(int i = a.length() + 'a' - 1; i >= 'a'; i--)
	{
		c.push(i);
	}
	for(int i = 0;i < a.length();i++)
	{
		while(!d.size() || d.top() != a.c_str()[i])
		{
			if(!c.size())
			{
				goto end;
			}
			b += "push\n";
			d.push(c.top());
			c.pop();
		}
		b += "pop\n";
		d.pop();
	}
	cout << b;
	return 0;
end:
	cout << "impossible";
	return 0;
}
