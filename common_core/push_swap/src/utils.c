/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:33:33 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/01 19:04:45 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	**init_stacks(char **args)
{
	int		i;
	int		size;
	int		**stacks;

	size = 0;
	while (args[size])
		size++;
	stacks = (int **)ft_calloc(2, sizeof(int *));
	stacks[0] = (int *)ft_calloc((size + 1), sizeof(int));
	stacks[1] = (int *)ft_calloc((size + 1), sizeof(int));
	stacks[0][0] = size;
	i = 0;
	while (++i <= stacks[0][0])
		stacks[0][i] = ft_atoi(args[i - 1]);
	format_stacks(stacks);
	return (stacks);
}

void	format_stacks(int **stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i <= stacks[0][0])
	{
		j = ++stacks[1][0];
		stacks[1][i] = stacks[0][i];
		while (stacks[1][j] < stacks[1][j - 1] && j > 1)
		{
			tmp = stacks[1][j - 1];
			stacks[1][j - 1] = stacks[1][j];
			stacks[1][j] = tmp;
			j--;
		}
	}
	while (--i > 0)
	{
		j = 1;
		while (stacks[0][i] != stacks[1][j])
			j++;
		stacks[0][i] = j;
	}
	stacks[1][0] = 0;
}

void	free_args(char **args)
{
	int	i;

	i = -1;
	if (args)
	{
		while (args[++i])
			free(args[i]);
		free(args[i]);
	}
	free(args);
}

void	free_stacks(int **stacks)
{
	free(stacks[0]);
	free(stacks[1]);
	free(stacks);
}
