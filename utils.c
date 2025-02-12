/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 05:00:30 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 08:31:44 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_putnbr_fd(stack->nbr, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

void	set_index(t_stack_node *node)
{
	int	i;
	int	median;

	if (!node)
		return ;
	i = 0;
	median = stack_size(node) / 2;
	while(node)
	{
		node->index = i;
		if (i <= median)
			node->b_above_median = false;
		else
			node->b_above_median = true;
		node = node->next;
		i++;
	}
}

void	init_node(t_stack_node *a, t_stack_node *b)
{
		set_index(a);
		set_index(b);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}