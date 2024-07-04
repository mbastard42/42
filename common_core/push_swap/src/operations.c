/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:26:52 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/12 19:43:16 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command(int **stacks, char *id)
{
	if (id[0] == 'p')
		push(stacks, id);
	if (id[0] == 's')
		swap(stacks, id, 0);
	if (id[0] == 'r')
	{
		if (id[1] == 'r' && id[2])
			r_rotate(stacks, id, 0);
		else
			rotate(stacks, id, 0);
	}
}

void	push(int **stacks, char *id)
{
	int	i;

	if (strchr("ab", id[1]) && stacks[98 - id[1]][0])
	{
		i = ++stacks[id[1] - 97][0];
		while (--i)
			stacks[id[1] - 97][i + 1] = stacks[id[1] - 97][i];
		stacks[id[1] - 97][1] = stacks[98 - id[1]][1];
		i = 0;
		while (++i < stacks[98 - id[1]][0])
			stacks[98 - id[1]][i] = stacks[98 - id[1]][i + 1];
		stacks[98 - id[1]][0]--;
		write(1, id, 2);
		write(1, "\n", 1);
	}
}

void	swap(int **stacks, char *id, int both)
{
	int	tmp;

	if (strchr("ab", id[1]) && stacks[id[1] - 97][0] > 1)
	{
		tmp = stacks[id[1] - 97][1];
		stacks[id[1] - 97][1] = stacks[id[1] - 97][2];
		stacks[id[1] - 97][2] = tmp;
		if (!both)
		{
			write(1, id, 2);
			write(1, "\n", 1);
		}
	}
	if (id[1] == 's')
	{
		swap(stacks, "sa", 1);
		swap(stacks, "sb", 1);
		write(1, id, 2);
		write(1, "\n", 1);
	}
}

void	rotate(int **stacks, char *id, int both)
{
	int	i;
	int	tmp;

	i = 0;
	if (strchr("ab", id[1]) && stacks[id[1] - 97][0] > 1)
	{
		tmp = stacks[id[1] - 97][1];
		while (++i < stacks[id[1] - 97][0])
			stacks[id[1] - 97][i] = stacks[id[1] - 97][i + 1];
		stacks[id[1] - 97][i] = tmp;
		if (!both)
		{
			write(1, id, 2);
			write(1, "\n", 1);
		}
	}
	if (id[1] == 'r')
	{
		rotate(stacks, "ra", 1);
		rotate(stacks, "rb", 1);
		write(1, id, 2);
		write(1, "\n", 1);
	}
}

void	r_rotate(int **stacks, char *id, int both)
{
	int	i;
	int	tmp;

	i = 0;
	if (strchr("ab", id[2]) && stacks[id[2] - 97][0] > 1)
	{
		i = stacks[id[2] - 97][0];
		tmp = stacks[id[2] - 97][i++];
		while (--i)
			stacks[id[2] - 97][i] = stacks[id[2] - 97][i - 1];
		stacks[id[2] - 97][1] = tmp;
		if (!both)
		{
			write(1, id, 3);
			write(1, "\n", 1);
		}
	}
	if (id[2] == 'r')
	{
		r_rotate(stacks, "rra", 1);
		r_rotate(stacks, "rrb", 1);
		write(1, id, 3);
		write(1, "\n", 1);
	}
}
