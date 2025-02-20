/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:25:42 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/17 14:46:21 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **head, t_stack_node **b)
{
	int				head_size = stack_size(head);
	int				current_size = head_size;
	t_stack_node	*cur_node;
	t_stack_node	*max_node;

	cur_node = (*head);
	init_node(*head, *b);
	while (head_size != current_size && !is_stack_sorted(head))
	{
		max_node = find_max_node(*head);
		if (max_node->index != (head_size - 1))
		{
			if (cur_node == max_node)
				pp(head, b, false);
		}
		if (is_stack_sorted(head) && is_stack_sorted(b))
		{
			
		}
	}
}