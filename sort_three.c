/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:31:34 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 11:50:07 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **head)
{
	t_stack_node	*max;
	t_stack_node	*min;

	max = find_max_node(*head);
	min = find_min_node(*head);
	if (max == *head)
		ra(head);
	else if (min == find_last_node(*head) || min == *head)
	{
		rra(head);
	}
	if (!is_stack_sorted(*head))
		sa(head);
}