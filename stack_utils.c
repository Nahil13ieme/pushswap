/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:26 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/24 16:43:44 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node *find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;
	t_stack_node	*current;
	
	if (!stack)
		return NULL;
	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->nbr < min_node->nbr)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node *find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	t_stack_node	*current;
	
	if (!stack)
		return NULL;
	max_node = stack;
	current = stack;
	while (current)
	{
		if (current->nbr > max_node->nbr)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

int stack_size(t_stack_node *stack)
{
	int	size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->b_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}