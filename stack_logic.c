/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:28:02 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/09 00:34:40 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n);

void	free_stack(t_stack_node *node)
{
	t_stack_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

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

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!ft_check_arg(argv[i]))
		{
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("Error: Wrong arg\n", 2);
			free_stack(*a);
			return ;
		}
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			ft_putstr_fd("Error: n is not INT\n", 2);
			free_stack(*a);
			return ;
		}
		if (!ft_check_duplicate(*a, (int)n))
		{
			ft_putnbr_fd(n, 1);
			ft_putchar_fd('\n', 1);
			ft_putstr_fd("Error: Duplicate value found\n", 2);
			free_stack(*a);
			return ;
		}
		append_node(a, (int)n);
		i++;
	}
}

static t_stack_node	*find_last_node(t_stack_node *stack)
{
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
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

int	is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}