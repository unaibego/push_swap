/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:30:34 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/01 12:09:11 by ubegona          ###   ########.fr       */
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
	if (i / 2 > j)
		return (j - i);
	else
		return (j);
}

void quick_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	while (*list_a != NULL)
	{		
		i = 0;
		j = find_minimum(list_a);
		while (i < j)
		{
			rotate_up(list_a);
			count++;
			i++;
		}
		while (i > j)
		{
			rotate_down(list_a);
			count++;
			i--;
		}
		push_b(list_a, list_b);
		count++;

	}
	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		count++;
		i++;
	}
	printf("%d mugimendu egin ditu quick sortek\n", count);
}
