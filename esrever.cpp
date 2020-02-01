#include <stdio.h>
#include <string.h>

int main()
{
	int tmp = 0;
	char a[81];
	char b[81];
	fgets(a, 80, stdin);
	int l = strlen(a);
	for(int i = 0;i < l;i++)
	{
		if(a[i] == ' ' || a[i] == '\n')
		{
			for(int j = i - 1;j >= tmp;j--)
			{
				printf("%c", a[j]);
			}
			if(a[i] == ' ')
			{
				printf(" ");
			}
			tmp = i + 1;
		}
	}
}
