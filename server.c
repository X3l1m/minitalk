#include <signal.h>
#include <unistd.h>
#include "libft/src/libft.h"




int	main(void)
{
	struct sigaction s_act;

	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	s_act.sa_sigaction = action;
	s_act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_act, 0);
	sigaction(SIGUSR2, &s_act, 0);
}