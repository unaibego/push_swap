/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_legend_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:24:59 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/16 09:14:24 by ubegona          ###   ########.fr       */
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
	j = 0;
	while (ds != NULL)
	{
		i++;
		if (minimo >= ds -> content)
		{
			minimo = ds -> content;
			j = i;
		}
		ds = ds -> next;
	}
	if (i / 2 <= j && i != 1)
		return (j - i);
	else
		return (j);
}

int	find_maximum(t_list **list_a)
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
	if (i / 2 < j && i != 1)
		return (j - i - 1);
	else
		return (j);
}

int	find_position(int pos, int len, int c, t_list **list_b)
{
	t_list	*ds;
	int		i;

	ds = *list_b;
	i = 0;
	if ((*list_b) != NULL && is_max_min(c, list_b))
	{
		if (absolut(find_minimum(list_b)) < absolut(find_maximum(list_b)))
			return (find_minimum(list_b));
		else
			return (find_maximum(list_b));
	}
	while (++i < len)
	{
		if (tartekoa_da(ds, ds -> next, c))
		{
			pos = i;
			break ;
		}
		ds = ds -> next;
	}
	if (pos > len / 2 && len != 1)
		return (pos - len);
	return (pos);
}

int	find_minimum_cost(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		minimo;

	ds = *list_a;
	minimo = absolut(ds -> pos_a) + absolut(ds -> pos_b);
	j = 0;
	i = 0;
	while (ds != NULL)
	{
		if (minimo > absolut(ds -> pos_a) + absolut(ds -> pos_b))
		{
			minimo = absolut(ds -> pos_a) + absolut(ds -> pos_b);
			j = i;
		}
		ds = ds -> next;
		i++;
	}
	return (j);
}

void	legend_quick_sort(t_list **list_a, t_list **list_b)
{
	t_list	*ds;
	int		i;
	int		j;

	while (*list_a != NULL)
	{
		fill_up_pos_a(list_a);
		fill_up_pos_b(list_a, list_b);
		i = 0;
		j = find_minimum_cost(list_a);
		ds = *list_a;
		while (j > i++)
			ds = ds -> next;
		do_dbl_movements(list_a, list_b, ds -> pos_a, ds -> pos_b);
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
	}
	do_dbl_movements(list_a, list_b, 0, find_minimum(list_b));
	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
}
