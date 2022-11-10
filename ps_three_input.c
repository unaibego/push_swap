/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:24:45 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 20:24:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum_three(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		minimo;

	ds = *list_a;
	minimo = ds -> content;
	i = 0;
	j = 0;
	while (ds != NULL)
	{
		if (minimo >= ds -> content)
		{
			minimo = ds -> content;
			j = i;
		}
		i++;
		ds = ds -> next;
	}
	return (j);
}

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

void	three_input(t_list **list_a, t_list **list_b)
{
	printf_list(list_a);
	printf("hau minimoa %d eta hau maximoa %d\n", find_minimum_three(list_a), find_maximum_three(list_a));
}