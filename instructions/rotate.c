/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:32:47 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/24 21:04:45 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
 * Le premier élément devient le dernier.
 * rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
 * Le premier élément devient le dernier.
 * rr : ra et rb en même temps.
*/
#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}		


void	ra(t_stack_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}