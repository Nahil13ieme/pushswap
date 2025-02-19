/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:17:36 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/17 14:01:55 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	free_all(t_stack_node *stack_a, t_stack_node *stack_b, char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while(argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	init_stack_a(&stack_a, argv);
	if (!is_stack_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if ( stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
		 	sort_stack(&stack_a, &stack_b);
	}
	print_stack(stack_a);
	if (argc == 2)
		free_all(stack_a, stack_b, argv);
	else
		free_all(stack_a, stack_b, NULL);
	return (0);
}