/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhami <nbenhami@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:17:36 by nbenhami          #+#    #+#             */
/*   Updated: 2025/02/12 08:33:57 by nbenhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Le but du jeu est de trier les nombres de la pile a par ordre croissant. Pour ce
 * faire, vous disposez des instructions suivantes :
 * sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
 * Ne fait rien s’il n’y en a qu’un ou aucun.
 * sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
 * Ne fait rien s’il n’y en a qu’un ou aucun.
 * ss : sa et sb en même temps.
 * pa (push a) : Prend le premier élément au sommet de b et le met sur a.
 * Ne fait rien si b est vide.
 * pb (push b) : Prend le premier élément au sommet de a et le met sur b.
 * Ne fait rien si a est vide.
 * rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
 * la pile a. Le dernier élément devient le premier.
 * rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
 * la pile b. Le dernier élément devient le premier.
 * rrr : rra et rrb en même temps.
*/

#include <stdio.h>
#include "push_swap.h"
// void	sa(int *a, int *b)
// {
// 	printf("sa");
// }
// void	sb(int *a, int *b)
// {
// 	printf("sb");
// }
// void	ss(int *a, int *b)
// {
// 	printf("ss");
// } 
// void	pa(int *a, int *b)
// {
// 	printf("pa");
// }
// void	pb(int *a, int *b)
// {
// 	printf("pb");
// }
// void	ra(int *a, int *b)
// {
// 	printf("ra");
// }
// void	rb(int *a, int *b)
// {
// 	printf("rb");
// }
// void	rr(int *a, int *b)
// {
// 	printf("rr");
// }
// void	rra(int *a, int *b)
// {
// 	printf("rra");
// }
// void	rrb(int *a, int *b)
// {
// 	printf("rrb");
// }
// void	rrr(int *a, int *b)
// {
// 	printf("rrr");
// }

void	free_all(t_stack_node *stack_a, t_stack_node *stack_b, char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while(argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	init_stack_a(&stack_a, argv);
	if (!is_stack_sorted(stack_a))
	{
		//if (stack_size(stack_a) == 3)
			ra(&stack_a);
		//else if ( stack_size(stack_a) == 3)
			//sort_three(&stack_a);
		// else
		// 	sort_stack(stack_a);
	}
	print_stack(stack_a);
	if (argc == 2)
		free_all(stack_a, NULL, argv);
	else
		free_all(stack_a, NULL, NULL);
	return (0);
}