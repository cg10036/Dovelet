#include <stdio.h>

void run(int a, int b)
{
	if(!a)
	{
		return;
	}
	int tmp = a % b;
	run(a / b, b);
	if(tmp > 9)
	{
		printf("%c", tmp - 10 + 'A');
	}
	else
	{
		printf("%d", tmp);
	}
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	run(a, b);
}
