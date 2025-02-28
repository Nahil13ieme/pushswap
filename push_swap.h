/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:25:34 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/28 14:17:54 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>

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

void			free_stack(t_stack_node **stack);
long			ft_atol(char *str);
int				ft_check_arg(char *str);
int				ft_check_duplicate(t_stack_node *stack, int n);
int				init_stack_a(t_stack_node **a, char **argv);
void			init_node_a(t_stack_node *a, t_stack_node *b);
void			init_node_b(t_stack_node *a, t_stack_node *b);
int				is_stack_sorted(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			print_stack(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
void			sort_three(t_stack_node **head);
void			sort_stack(t_stack_node **head, t_stack_node **b);
void			reverse(t_stack_node **head);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			set_index(t_stack_node *head, int link_size);
void			update_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			init_push(t_stack_node **stack, t_stack_node *top, bool is_a);
#endif