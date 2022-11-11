/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:39:38 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/11 10:17:37 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_first(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL || *list_b == NULL)
		return (0);
	return ((*list_a) -> content >= (*list_b) -> content);
}

void	quick_sort_bubble(t_list **list_a, t_list **list_b)
{
	int	i;
	int	j;

	while (*list_a != NULL && find_minimum_five(list_a) < 0)
	{		
		i = 0;
		j = find_minimum_five(list_a);
		while (i > j)
		{
			rotate_down(list_a);
			write(1, "rra\n", 4);
			i--;
		}
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
	}
}

void	bubble(t_list **list_a, t_list **list_b)
{
	while ((!list_is_sort(list_a) || *list_b != NULL))
	{
		quick_sort_bubble(list_a, list_b);
		if (*list_a != NULL && compare_first(list_a, &((*list_a) -> next)))
		{
			if (*list_b != NULL && compare_first(&((*list_b) -> next), list_b))
			{
				swap_a(list_a);
				swap_a(list_b);
				write(1, "ss\n", 3);
			}
			else
			{
				swap_a(list_a);
				write(1, "sa\n", 3);
			}
		}
		if (list_is_sort(list_a) && *list_b == NULL)
			break ;
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
		if (*list_a == NULL || list_is_sort(list_a))
		{
			while (*list_b != NULL)
			{
				if (*list_b != NULL && compare_first(&((*list_b) -> next), list_b))
				{
					if (*list_a != NULL && compare_first(list_a, &((*list_a) -> next)))
					{
						swap_a(list_a);
						swap_a(list_b);
						write(1, "ss\n", 3);
					}
					else
					{
						swap_a(list_b);
						write(1, "sb\n", 3);
					}
				}
				push_b(list_b, list_a);
				write(1, "pa\n", 3);
			}
		}
	}
}
