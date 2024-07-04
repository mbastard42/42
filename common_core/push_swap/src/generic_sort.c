/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:26:36 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/12 19:38:29 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(int **stacks)
{
	int	size;
	int	bit_weight;
	int	max_bit_weight;

	bit_weight = 1;
	max_bit_weight = get_max_bit_weight(stacks);
	while (bit_weight <= max_bit_weight)
	{
		size = stacks[0][0];
		while (size--)
		{
			if (stacks[0][1] & bit_weight)
				command(stacks, "ra");
			else
				command(stacks, "pb");
		}
		while (stacks[1][0])
			command(stacks, "pa");
		bit_weight <<= 1;
	}
}

int	get_max_bit_weight(int **stacks)
{
	int	max;
	int	bit_weight;

	bit_weight = 1;
	max = stacks[0][0];
	while (max > 1)
	{
		max >>= 1;
		bit_weight <<= 1;
	}
	return (bit_weight);
}
