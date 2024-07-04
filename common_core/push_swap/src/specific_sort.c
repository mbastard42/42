/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:26:36 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/12 19:41:49 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	specific_sort(int **stacks)
{
	if (stacks[0][0] == 2)
		sort_duo(stacks);
	if (stacks[0][0] == 3)
		sort_trio(stacks);
	if (stacks[0][0] == 4)
		sort_quartet(stacks);
	if (stacks[0][0] == 5)
		sort_quintet(stacks);
}

void	sort_duo(int **stacks)
{
	if (stacks[0][1] > stacks[0][2])
		command(stacks, "ra");
}

void	sort_trio(int **stacks)
{
	while (check_stacks(stacks))
	{
		if (stacks[0][1] == 1)
			command(stacks, "sa");
		if (stacks[0][1] == 2)
		{
			if (stacks[0][2] == 1)
				command(stacks, "sa");
			else if (stacks[0][2] == 3)
				command(stacks, "rra");
		}
		if (stacks[0][1] == 3)
		{
			if (stacks[0][2] == 1)
				command(stacks, "ra");
			else if (stacks[0][2] == 2)
				command(stacks, "sa");
		}
	}
}

void	sort_quartet(int **stacks)
{
	if (stacks[0][4] == 4)
		command(stacks, "rra");
	else
		while (stacks[0][1] != 4)
			command(stacks, "ra");
	command(stacks, "pb");
	sort_trio(stacks);
	command(stacks, "pa");
	command(stacks, "ra");
}

void	sort_quintet(int **stacks)
{
	int	i;

	i = 1;
	while (stacks[0][i] != 5)
		i++;
	if (i <= 3)
		while (stacks[0][1] != 5)
			command(stacks, "ra");
	else
		while (stacks[0][1] != 5)
			command(stacks, "rra");
	command(stacks, "pb");
	sort_quartet(stacks);
	command(stacks, "pa");
	command(stacks, "ra");
}
