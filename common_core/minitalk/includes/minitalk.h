/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:30:18 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/01 19:03:16 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

//		client.c functions

/**
 * @brief 	converts the string (str) to an integer
 *
 * @param str 	string to convert
 * @return 		str converted to an integer
 */
int		ft_mini_atoi(const char *str);
/**
 * @brief 	handle byte reception signal (sig) send by server
 *
 * @param sig reception signal
 */
void	handle_signal(int sig);
/**
 * @brief 	send a byte (c) to the server process identified by (server_pid)
 *
 * @param server_pid 	server process pid
 * @param c 			byte to send
 */
void	kill_byte(int server_pid, char c);

//		server.c functions

/**
 * @brief 	writes the unsigned number (nbr) to the output (fd)
 *
 * @param fd 	file descriptor
 * @param nbr 	unsigned number to write
 */
void	ft_putunbr_fd(int fd, size_t nbr);
/**
 * @brief 	receive byte through signal (sig) from client process identified by
 * 			(info) and confirm reception
 *
 * @param sig		signal from client process
 * @param info		client process pid
 * @param context 	unused parameter
 */
void	receive_byte(int sig, siginfo_t *info, void *context);

#endif
