/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:00:02 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/01 19:04:45 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(char **args)
{
	if (!check_if_nbr(args))
		return (write(1, "Error\nSome arguments aren't numbers\n", 36));
	if (!check_if_int(args))
		return (write(1, "Error\nSome arguments aren't integers\n", 37));
	if (!check_duplicate(args))
		return (write(1, "Error\nArguments contain duplicates\n", 35));
	return (0);
}

int	check_if_nbr(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		if (!strchr("+-0123456789", args[i][j]))
			return (0);
		if (strchr("+-", args[i][j]) && !args[i][j + 1])
			return (0);
		while (args[i][++j])
			if (!strchr("0123456789", args[i][j]))
				return (0);
	}
	return (1);
}

int	check_if_int(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		if (strchr("+-", args[i][j]))
			j++;
		while (args[i][j] == '0')
			j++;
		if (strlen(&args[i][j]) >= 10)
		{
			if (args[i][j] > '2')
				return (0);
			if (args[i][j] == '2')
			{
				if (args[i][0] == '-' && ft_atoi(&args[i][j + 1]) > 147483648)
					return (0);
				if (args[i][0] != '-' && ft_atoi(&args[i][j + 1]) > 147483647)
					return (0);
			}
		}
	}
	return (1);
}

int	check_duplicate(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		while (args[i + ++j])
			if (ft_atoi(args[i]) == ft_atoi(args[i + j]))
				return (0);
	}
	return (1);
}

int	check_stacks(int **stacks)
{
	int	i;

	i = 0;
	while (++i <= stacks[0][0])
		if (stacks[0][i] != i)
			return (1);
	return (0);
}
