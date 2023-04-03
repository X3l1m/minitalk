#include <signal.h>
#include <unistd.h>
#include "libft/src/libft.h"


void	r_kill(int num, siginfo_t *info, void *cortex)
{
	(void)cortex;
	int	i;
	unsigned char  c = 0;

	if (num == SIGUSR1)
		c |= 
	
}




int	main(void)
{
	struct signalaction s_act;
	s_act.sa_sigaction = r_kill;
	s_act.sa_flags = SA_SIGINFO;
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, r_kill, 0);
	sigaction(SIGUSR2, r_kill, 0);
	while (1)
		pause();
}