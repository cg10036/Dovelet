#include <stdio.h>
#include <string.h>

int main()
{
	int a[26] = { 0 };
	char b[101];
	scanf("%s", b);
	for(int i = 0;i < strlen(b);i++)
	{
		a[b[i] - 'a']++;
	}
	for(int i = 0;i < 26;i++)
	{
		printf("%c:%d\n", i + 'a', a[i]);
	}
}
