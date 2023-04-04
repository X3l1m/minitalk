#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main()
{	
	int i = 0b00000000;
	char c = 0;
	c |= i;
	printf("%c\n", c);
	return 0;
}
