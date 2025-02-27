/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 05:00:30 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/27 14:05:09 by nbenhami         ###   ########.fr       */
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

void	init_node(t_stack_node *a, t_stack_node *b)
{
	(void)a;
	(void)b;
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

void	init_push(t_stack_node **stack, t_stack_node *top, bool is_a)
{
	while (*stack != top)
	{
		if (is_a)
		{
			if (top->b_above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top->b_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
