/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:32:47 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 08:30:44 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
 * Le premier élément devient le dernier.
 * rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
 * Le premier élément devient le dernier.
 * rr : ra et rb en même temps.
*/
#include "../push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	last_node = find_last_node((*head));
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}