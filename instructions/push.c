/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:39:04 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 08:58:52 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* pa (push a) : Prend le premier élément au sommet de b et le met sur a.
 * Ne fait rien si b est vide.
 * pb (push b) : Prend le premier élément au sommet de a et le met sur b.
 * Ne fait rien si a est vide.
*/

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;
	if (!*src || !src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	pp(t_stack_node **a, t_stack_node **b, bool b_to_a)
{
	if (b_to_a)
	{
		push(a, b);
		ft_putstr_fd("pa", 1);
	}
	else
	{
		push(b, a);
		ft_putstr_fd("pb", 1);
	}
}