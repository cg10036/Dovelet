#include <stdio.h>

void hanoi(int n, int a, int b, int c) // ���� ��, �����, ������, �ӽ������
{
	if(n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("%d -> %d\n", a, b);
		hanoi(n - 1, c, b, a);
	}
} 

int main()
{
	int a;
	scanf("%d", &a);
	hanoi(a, 1, 3, 2);
}
