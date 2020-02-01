#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <malloc.h>

using namespace std;

int a, b;
char *c;

void chk(string e)
{
	int g = 0, h = 0;
	for(int i = 'a';i <= 'z';i++)
	{
		if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
		{
			if(e.find(i) != std::string::npos)
			{
				g++;
			}
		}
		else
		{
			if(e.find(i) != std::string::npos)
			{
				h++;
			}
		}
	}
	if(g && h)
	{
		cout << e << endl;
	}
}

void run(int d, string e, int f)
{
	if(d == a)
	{
		chk(e);
		return;
	}
	for(int i = f;i < b;i++)
	{
		run(d + 1, e + c[i], i + 1);
	}
}

int main()
{
	scanf("%d %d", &a, &b);
	c = (char*)malloc(b * sizeof(char));
	string e;
	for(int i = 0;i < b;i++)
	{
		scanf("%c", &c[i]);
		if(c[i] == ' ' || c[i] == '\n')
		{
			i--;
		}
	}
	sort(c, c + b);
	run(0, e, 0);
}
