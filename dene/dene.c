#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main()
{	
	int i = 0b01010101;
	char c = 0;
	c |= i;
	printf("%c\n", c);
	return 0;
}
