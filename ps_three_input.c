/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:24:45 by marvin            #+#    #+#             */
/*   Updated: 2022/11/11 10:07:12 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_maximum_three(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		maximo;

	ds = *list_a;
	maximo = ds -> content;
	i = 0;
	j = 0;
	while (ds != NULL)
	{
		if (maximo < ds -> content)
		{
			maximo = ds -> content;
			j = i;
		}
		ds = ds -> next;
		i++;
	}
	return (j);
}

int	three_inputs(t_list **list_a, t_list **list_b)
{
	if (list_is_sort(list_a))
		return (0);
	if (find_maximum_three(list_a) == 1)
		do_dbl_movements(list_a, list_b, -1, 0);
	if (find_maximum_three(list_a) == 0)
		do_dbl_movements(list_a, list_b, 1, 0);
	if (list_is_sort(list_a))
		return (0);
	swap_a(list_a);
	write(1, "sa\n", 3);
	return (0);
}
