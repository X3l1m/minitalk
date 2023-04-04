#include <signal.h>
#include <unistd.h>
#include "libft/src/libft.h"


void	r_kill(int num, siginfo_t *info, void *cortex)
{
	(void)cortex;
	static int	i = 0;
	static pid_t	client_pid = 0;
	static unsigned char	c = 0;

	if(!client_pid)
		client_pid = info->si_pid;
	c |= (num == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		write(1, &c, 1);
		kill(client_pid, SIGUSR1);
		c = 0;
	}
	else
		c <<= 1;
}


int	main(void)
{
	struct sigaction s_act;

	s_act.sa_sigaction = &r_kill;
	s_act.sa_flags = SA_SIGINFO;
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &s_act, 0);
	sigaction(SIGUSR2, &s_act, 0);
	while (1)
		pause();
}