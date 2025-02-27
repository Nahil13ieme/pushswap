/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:25:42 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/27 14:00:08 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	d_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b);
	update_index(*a);
	update_index(*b);
}

static void	r_d_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b);
	update_index(*a);
	update_index(*b);
}

static void	put_min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min_node(*a)->nbr)
	{
		if (find_min_node(*a)->b_above_median)
			ra(a);
		else
			rra(a);
	}
}

static void	move(t_stack_node **a, t_stack_node **b, bool node_a)
{
	t_stack_node	*cheap;

	if (node_a)
	{
		cheap = get_cheapest_node(*a);
		if (cheap->b_above_median
			&& cheap->target_node->b_above_median)
			d_rotate(a, b, cheap);
		else if (!(cheap->b_above_median)
			&& !(cheap->target_node->b_above_median))
			r_d_rotate(a, b, cheap);
		init_push(a, cheap, true);
		init_push(b, cheap->target_node, false);
		pb(a, b);
	}
	else
	{
		init_push(a, (*b)->target_node, true);
		pa(a, b);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_size(*a);
	if (len-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	if (len-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	while (len-- > 3 && !is_stack_sorted(*a))
	{
		init_node_a(*a, *b);
		move(a, b, true);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move(a, b, false);
	}
	update_index(*a);
	put_min_on_top(a);
}
