#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/src/libft.h"

void	s_act(int num)
{
	static int	recived = 0;

	if (num == SIGUSR1)
		recived++;
	else
	{
		ft_putnbr_fd(recived, 1);
		write(1, "\n", 1);
		exit(0);
	}
}


void	s_kill(int pid, char *msg)
{
	int		i;
	char	m;

	while (*msg)
	{
		i = 8;
		m = *msg++;
		while (--i)
		{
			if (m >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
	}
 	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		sleep(1);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return(1);
	write(1, "Sent: ", 6);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	write(1, "\n", 1);
	write(1, "Recived:", 8);
	signal(SIGUSR1, s_act);
	signal(SIGUSR1, s_act);
	s_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}