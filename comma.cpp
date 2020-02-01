#include <stdio.h>
#include <string.h>

int main()
{
	char a[101];
	scanf("%s", a);
	for(int i = 0;i < strlen(a);i++)
	{
		if(i + 1 > strlen(a) % 3 && (i - strlen(a) % 3) % 3 == 0 && i)
		{
			printf(",");
		}
		printf("%c", a[i]);
	}
}
