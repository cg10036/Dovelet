#include <iostream>

using namespace std;

int a;

void run(int b, string str)
{
	str = str + to_string(b) + str;
	if(b == a)
	{
		cout << str;
		return;
	}
	run(++b, str);
}

int main()
{
	cin >> a;
	run(1, string(""));
}
