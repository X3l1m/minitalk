#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/src/libft.h"

int	g_recived = 0;

void	s_act(int num)
{
	if (num == SIGUSR1)
		g_recived++;
	else
	{
		ft_putnbr_fd(g_recived, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

void	send_error(void)
{
	write(1, "0\nMessage could not send or crash.\n", 35);
	exit(1);
}

void	world_end(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	s_kill(int pid, char *msg)
{
	int		past_re;
	int		i;
	char	m;

	past_re = 0;
	while (*msg)
	{
		i = 8;
		m = *msg++;
		while (i--)
		{	
			if (m >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		if (g_recived < past_re++)
			send_error();
	}
	world_end(pid);
	sleep(3);
	send_error();
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Missing argument.\n", 18);
		return (1);
	}
	if (!ft_strlen(argv[2]))
	{
		write(1, "No message input.\n", 18);
		return (1);
	}
	write(1, "Sent   : ", 9);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	write(1, "\n", 1);
	write(1, "Recived: ", 9);
	signal(SIGUSR1, s_act);
	signal(SIGUSR2, s_act);
	s_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
