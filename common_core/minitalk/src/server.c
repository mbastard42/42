/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:30:11 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/31 21:49:36 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putunbr_fd(int fd, size_t nbr)
{
	if (nbr >= 10)
		ft_putunbr_fd(fd, nbr / 10);
	write(fd, &"0123456789"[nbr % 10], 1);
}

void	receive_byte(int sig, siginfo_t *info, void *context)
{
	static int	client_pid = 0;
	static char	c = '\0';
	static int	bit_weight = 128;

	if (info->si_pid)
		client_pid = info->si_pid;
	c = c | (bit_weight * (sig - SIGUSR1));
	bit_weight >>= 1;
	if (!bit_weight)
	{
		if (c)
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
			usleep(30);
			kill(client_pid, SIGUSR2);
		}
		c = '\0';
		bit_weight = 128;
	}
	usleep(30);
	kill(client_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_byte;
	write(1, "Server PID: ", 12);
	ft_putunbr_fd(1, getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
