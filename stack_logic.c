/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:28:02 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/28 14:17:41 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n);

long	ft_atol(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	ft_check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (!((str[i] == '-' || str[i] == '+')
					&& (i == 0 || str[i - 1] == ' ')
					&& str[i + 1] && ft_isdigit(str[i + 1])))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->nbr == n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!ft_check_arg(argv[i]))
			return (0);
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648
			|| !ft_check_duplicate(*a, (int)n))
			return (0);
		append_node(a, (int)n);
		i++;
	}
	return (1);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
