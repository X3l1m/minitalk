#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void durma(int sayi)
{
	write(STDOUT_FILENO, "ben durmam kardes\n", 18);
}


int main()
{	
	signal(SIGINT, durma);
	kill(getpid(), SIGINT);
	while (1)
	{
		printf("Domateslendin\n");
		sleep(1);
	}
	return 1;
}
