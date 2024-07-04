/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:30:01 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/01 19:03:16 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_mini_atoi(const char *str)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (str[++i])
		result = result * 10 + (str[i] - 48);
	return (result);
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Message received by server\n", 28);
		exit(0);
	}
}

void	kill_byte(int server_pid, char c)
{
	int	bit_weight;

	bit_weight = 128;
	while (bit_weight)
	{
		kill(server_pid, SIGUSR1 + (c & bit_weight) / bit_weight);
		bit_weight >>= 1;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					server_pid;

	sa.sa_handler = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		server_pid = ft_mini_atoi(argv[1]);
		while (*argv[2])
		{
			kill_byte(server_pid, *argv[2]);
			argv[2]++;
		}
		kill_byte(server_pid, 0);
	}
}
