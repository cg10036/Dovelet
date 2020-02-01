#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int i;
	string a;
	string b = "";
	stack<int> s;
	cin >> a;
	for(i = 0;i < a.length();i++)
	{
		if(a.c_str()[i] == '(')
		{
			s.push(i);
		}
		else if(a.c_str()[i] == ')')
		{
			if(!s.size())
			{
				break;
			}
			b += to_string(s.top()) + " " + to_string(i) + "\n";
			s.pop();
		}
	}
	if(!(i < a.length()) && !s.size())
	{
		cout << b;
	}
	else
	{
		cout << "not match";
	}
}
