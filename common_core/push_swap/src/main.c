/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:33:33 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/05 20:19:39 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*input;
	char	**args;
	int		**stacks;

	i = 0;
	input = NULL;
	if (argc)
	{
		while (++i <= argc)
			input = ft_multijoin("100", input, argv[i], " ");
		args = ft_split(input, ' ');
		free(input);
		if (!check_args(args))
		{
			stacks = init_stacks(args);
			if (check_stacks(stacks) && stacks[0][0] <= 5)
				specific_sort(stacks);
			if (check_stacks(stacks) && stacks[0][0] > 5)
				radix_sort(stacks);
			free_stacks(stacks);
		}
		free_args(args);
	}
	return (0);
}
