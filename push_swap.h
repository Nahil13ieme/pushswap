/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:25:34 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/09 00:35:53 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "Libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					b_above_median;
	int					b_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

void	free_stack(t_stack_node *node);
long	ft_atol(char *str);
int		ft_check_arg(char *str);
int		ft_check_duplicate(t_stack_node *stack, int n);
void	init_stack_a(t_stack_node **a, char **argv);
int		is_stack_sorted(t_stack_node *stack);

#endif