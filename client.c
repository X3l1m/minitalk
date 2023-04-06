/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 18:15:24 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/06 10:25:33 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

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

void	send_error(int error, int pid)
{
	if (error == 1)
		write(1, "Missing argument.\n", 18);
	else if (error == 2)
		write(1, "No message input.\n", 18);
	else if (error == 3)
		write(1, "\nCheck PID again.\n", 18);
	else if (error == 4)
	{
		write(1, "0\nMessage could not send or crash.\nRun server again.\n", 53);
		kill(pid, SIGKILL);
	}
	exit(1);
}

void	world_end(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
	sleep(3);
	send_error(4, pid);
}

void	s_kill(int pid, char *msg)
{
	int		i;
	char	m;

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
			usleep(200);
		}
		if (!g_recived)
			send_error(3, 0);
	}
	world_end(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		send_error(1, 0);
	if (!ft_strlen(argv[2]))
		send_error(2, 0);
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
