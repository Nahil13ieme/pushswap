/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:25:42 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/23 21:19:51 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Je veux faire une fonction recursive qui trouve la meilleure target possible.
	Pour cela je dois voir dans quel ordre envoyer les nodes dans B.
	
*/
t_stack_node	*find_target(t_stack_node **head)
{
	t_stack_node	*target;
	t_stack_node	*current;
	int				cost_to_push;

	current = *head;
	target = current;
	cost_to_push = 2147483647;
	while (current)
	{
		if (target->nbr < current->nbr && current->index < target->index)
		{
			if (cost_to_push > current->index)
			{
				target = current;
				cost_to_push = current->index;
			}
		}
		current = current->next;
	}
	return (target);
}

static int	can_align(t_stack_node **head)
{
	t_stack_node	*current;
	bool			can_break;

	current = *head;
	can_break = false;
	while (current->next)
	{
		if (current->nbr > current->next->nbr && can_break)
			return (0);
		if (current->nbr > current->next->nbr)
			can_break = true;
		current = current->next;
	}
	return (1);
}

static void	align_stack_a(t_stack_node **head)
{
	t_stack_node	*min;
	int				median;

	min = find_min_node(*head);
	median = stack_size(*head) / 2;
	if (min->index < median)
	{
		while (*head != min)
			ra(head);
	}
	else
	{
		while (*head != min)
			rra(head);
	}
}

void	align_stacks(t_stack_node **head, t_stack_node **b)
{
	t_stack_node	*target_a;
	t_stack_node	*target_b;
	int				median;

	median = stack_size(*head) / 2;
	target_b = find_max_node(*b);
	if (target_b->nbr < find_max_node(*head))
	{
		
	}
}

void	sort_stack(t_stack_node **head, t_stack_node **b)
{
	//int				head_size = stack_size(*head);
	//t_stack_node	*target;

	init_node(*head, *b);
	if (can_align(head))
	{
		align_stack_a(head);
		return ;
	}
	//while (head_size > 3)
	//{
	//	target = find_target(head);
	//	while (target != *head)
	//	{
	//		if (target->b_above_median)
	//			rra(head);
	//		else
	//			ra(head);
	//	}
	//	pp(head, b, false);
	//	head_size--;
	//}
	//align_stack_a(head);
}