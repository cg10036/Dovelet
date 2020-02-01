#include <iostream>

using namespace std;

int a, b;

void run(int c, int d, string e)
{
	if(c == a)
	{
		if(d == b)
		{
			cout << e << endl;
		}
		return;
	}
	if(d < b)
	{
		run(c + 1, d + 1, e + "1");
	}
	run(c + 1, d, e + "0");
}

int main()
{
	cin >> a >> b;
	run(0, 0, "");
}
