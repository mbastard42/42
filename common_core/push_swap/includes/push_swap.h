/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 02:12:52 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/14 18:20:14 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

//		checks.c functions

/**
 * @brief 	check if arguments are valid
 *
 * @param args	arguments
 * @return		0 if arguments are valid
 */
int		check_args(char **args);
/**
 * @brief 	check if arguments are numbers
 *
 * @param args 	arguments
 * @return		1 if arguments are numbers
 */
int		check_if_nbr(char **args);
/**
 * @brief 	check if arguments are integers
 *
 * @param args	arguments
 * @return		1 if arguments are integers
 */
int		check_if_int(char **args);
/**
 * @brief 	check if arguments doesn't contain duplicates
 *
 * @param args 	arguments
 * @return		1 if arguments doesn't contain duplicates
 */
int		check_duplicate(char **args);
/**
 * @brief 	check if stack_a need to be sorted
 *
 * @param stacks 	stack a and b
 * @return 			1 if stack_a need to be sorted
 */
int		check_stacks(int **stacks);

//		generic_sort.c functions

/**
 * @brief 	sort stacks using bits comparison
 *
 * @param stacks 	stacks a and b
 */
void	radix_sort(int **stacks);
/**
 * @brief 	determine the max significant bit_weight in stack a
 *
 * @param stacks 	stacks a and b
 * @return 			max significant bit_weight
 */
int		get_max_bit_weight(int **stacks);

//		operations.c functions

/**
 * @brief 	receive, execut and print an operation
 *
 * @param stacks	stacks a and b
 * @param id		operation identifier
 */
void	command(int **stacks, char *id);
/**
 * @brief 	push the first element of one stack to the top of the other
 *
 * @param stacks	stacks a and b
 * @param id		operation identifier
 */
void	push(int **stacks, char *id);
/**
 * @brief 	swap the first of a stack with the second one
 *
 * @param stacks	stacks a and b
 * @param id		operation identifier
 * @param both		equal 1 when swaping both stacks
 */
void	swap(int **stacks, char *id, int both);
/**
 * @brief 	rotate a stack upwards
 *
 * @param stacks	stacks a and b
 * @param id		operation identifier
 * @param both		equal 1 when rotating both stacks
 */
void	rotate(int **stacks, char *id, int both);
/**
 * @brief 	rotate a stack downwards
 *
 * @param stacks	stacks a and b
 * @param id		operation identifier
 * @param both		equal 1 when rotating both stacks
 */
void	r_rotate(int **stacks, char *id, int both);

//		specific_sort.c functions

/**
 * @brief 	choose wich specific algorithm to choose
 *
 * @param stacks stacks a and b
 */
void	specific_sort(int **stacks);
/**
 * @brief 	sort list with 2 elements
 *
 * @param stacks stacks a and b
 */
void	sort_duo(int **stacks);
/**
 * @brief 	sort list with 3 elements
 *
 * @param stacks stacks a and b
 */
void	sort_trio(int **stacks);
/**
 * @brief 	sort list with 4 elements
 *
 * @param stacks stacks a and b
 */
void	sort_quartet(int **stacks);
/**
 * @brief 	sort list with 5 elements
 *
 * @param stacks stacks a and b
 */
void	sort_quintet(int **stacks);

//		utils.c functions

/**
 * @brief 	initialize stacks a and b and fill them with arguments
 *
 * @param args 		arguments
 * @return 			initialized stacks
 */
int		**init_stacks(char **args);
/**
 * @brief 	format values of stack_a
 *
 * @param stacks 	stacks a and b
 */
void	format_stacks(int **stacks);
/**
 * @brief 	free memory allocated to stock arguments
 *
 * @param args 	arguments
 */
void	free_args(char **args);
/**
 * @brief 	free memory allocated to stock stacks
 *
 * @param stacks 	stacks a and b
 */
void	free_stacks(int **stacks);

#endif
