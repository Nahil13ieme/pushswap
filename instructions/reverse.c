/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:31:58 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 11:47:45 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
 * la pile a. Le dernier élément devient le premier.
 * rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
 * la pile b. Le dernier élément devient le premier.
 * rrr : rra et rrb en même temps.
*/

void	reverse(t_stack_node **head)
{
	t_stack_node	*last;

	last = find_last_node(*head);
	last->prev->next = NULL;
	last->next = (*head);
	last->prev = NULL;
	(*head)->prev = last;
	(*head) = last;
}

void	rra(t_stack_node **a)
{
	reverse(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b)
{
	reverse(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr\n", 1);
}