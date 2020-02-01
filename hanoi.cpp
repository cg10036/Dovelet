#include <stdio.h>

void hanoi(int n, int a, int b, int c) // 접시 수, 출발지, 도착지, 임시저장소
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
