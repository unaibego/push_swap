/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:30:34 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/02 14:11:22 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		minimo;

	ds = *list_a;
	minimo = ds -> content;
	i = 0;
	while (ds != NULL)
	{
		if (minimo >= ds -> content)
		{
			minimo = ds -> content;
			j = i;
		}
		ds = ds -> next;
		i++;
	}
	// printf("hau j==|%d| eta hau i==!%d|\n", j, i);
	if (i / 2 < j)
		return (j - i);
	else
		return (j);
}

void	quick_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	j;

	while (*list_a != NULL)
	{		
		i = 0;
		j = find_minimum(list_a);
		while (i < j)
		{
			rotate_up(list_a);
			write(1, "ra\n", 3);
			i++;
		}
		while (i > j)
		{
			rotate_down(list_a);
			write(1, "rra\n", 4);
			i--;
		}
		push_b(list_a, list_b);
		write(1, "pb\n", 3);

	}
	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
	// printf("%d mugimendu egin ditu quick sortek\n", count);
}
