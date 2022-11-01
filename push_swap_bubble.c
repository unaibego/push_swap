/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:39:38 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/01 12:09:01 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_first(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL || *list_b == NULL)
		return (0);
	return((*list_a) -> content <= (*list_b) -> content);
}

void	bubble(t_list **list_a, t_list **list_b)
{
	int	i;

	i = 0;
	while ((!list_is_sort(list_a) || *list_b != NULL))
	{
		push_b(list_a, list_b);
		i++;
		if (compare_first(list_a, list_b))
		{
			push_b(list_b, list_a);
			i++;
			swap_a(list_a);
			i++;
			push_b(list_a, list_b);
			i++;
		}
		if (*list_a == NULL)
		{
			while (*list_b != NULL)
			{
				push_b(list_b, list_a);
				i++;
			}
		}
	}
	printf("%d mugimendu egin ditu bubblek\n", i);
}
