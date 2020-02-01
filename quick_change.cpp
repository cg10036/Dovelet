#include <iostream>

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d QUARTER(S), ", a / 25);
	a %= 25;
	printf("%d DIME(s), ", a / 10);
	a %= 10;
	printf("%d NICKEL(S), ", a / 5);
	a %= 5;
	printf("%d PENNY(S)", a);
}
