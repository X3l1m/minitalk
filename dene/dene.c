#include <stdio.h>


int domat = 45;

void func(void)
{
	domat++;
}
int main()
{	
	func();
	printf("%d", domat);
	return 0;
}