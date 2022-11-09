/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_legend_quick_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:24:59 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/09 13:27:11 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_lstsize(t_list *lst)
{
	t_list	*ds;
	int		i;

	ds = lst;
	i = 0;
	while (ds != NULL)
	{
		ds = ds ->next;
		i++;
	}
	return (i);
}

void	fill_up_posA(t_list **list_a)
{
	t_list	*ds;
	float	len;
	int		i;

	ds = *list_a;
	len = ft_lstsize(*list_a);
	i = 0;
	while (i < len / 2)
	{
		ds -> posA = i;
		ds = ds -> next;
		i++;
	}
	while (ds != NULL)
	{
		ds -> posA = (len) / -2;
		ds = ds -> next;
		len = len - 2;
	}

}

void	fill_up_posB(t_list **list_a, t_list **list_b)
{
	t_list	*ds;
	int		minimo;
	int		len;

	ds = *list_a;
	minimo = ds -> content;
	len = ft_lstsize(*list_b);
	while (ds != NULL)
	{
		ds -> posB = find_position(len, ds -> content, list_b);
		ds = ds -> next;
	}
}

int	tartekoa_da(t_list *aurrekoa, t_list *hurrengoa, int c)
{
	if (hurrengoa == NULL)
	{
		return (0);
	}
	if (aurrekoa -> content > c)
	{
		if (hurrengoa -> content < c)
			return (1);
	}
	return (0);
}

int	is_max(int c, t_list **list_b)
{
	t_list	*ds;

	ds = *list_b;
	while (ds != NULL)
	{
		if (c < ds -> content)
			return (0);
		ds = ds -> next;
	}
	return (1);
}

int	is_min(int c, t_list **list_b)
{
	t_list	*ds;

	ds = *list_b;
	while (ds != NULL)
	{
		if (c > ds -> content)
			return (0);
		ds = ds -> next;
	}
	return (1);
}

int	is_max_min(int c, t_list **list_b)
{
	if (is_min(c, list_b) || is_max(c, list_b))
		return (1);
	return (0);
}

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

int	find_position(int len, int c, t_list **list_b)
{
	t_list	*ds;
	int		i;
	int		pos;

	ds = *list_b;
	i = 0;
	pos = 0;
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

int	absolut(int c)
{
	if (c < 0)
		return (-1 * c);
	else
		return (c);
}

int	find_minimum_cost(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		minimo;

	ds = *list_a;
	minimo = absolut(ds -> posA) + absolut(ds -> posB);
	j = 0;
	i = 0;
	while (ds != NULL)
	{
		if (minimo > absolut(ds -> posA) + absolut(ds -> posB))
		{
			minimo = absolut(ds -> posA) + absolut(ds -> posB);
			j = i;
		}
		ds = ds -> next;
		i++;
	}
	return (j);
}

void	do_doble_movements(t_list **list_a, t_list **list_b, int posA, int posB)
{
	while (posA < 0 && posB < 0)
	{
		rotate_down(list_a);
		rotate_down(list_b);
		write(1, "rrr\n", 4);
		posA++;
		posB++;
	}
	while (posA > 0 && posB > 0)
	{
		rotate_up(list_a);
		rotate_up(list_b);
		write(1, "rr\n", 3);
		posA--;
		posB--;
	}
	do_sgl_movements(list_a, list_b, posA, posB);
}


void	do_sgl_movements(t_list **list_a, t_list **list_b, int posA, int posB)
{
	while (posA < 0)
	{
		rotate_down(list_a);
		write(1, "rra\n", 4);
		posA++;
	}
	while (posA > 0)
	{
		rotate_up(list_a);
		write(1, "ra\n", 3);
		posA--;
	}
	while (posB < 0)
	{
		rotate_down(list_b);
		write(1, "rrb\n", 4);
		posB++;
	}
	while (posB > 0)
	{
		rotate_up(list_b);
		write(1, "rb\n", 3);
		posB--;
	}
}

void	legend_quick_sort(t_list **list_a, t_list **list_b)
{
	t_list	*ds;
	int		i;
	int		j;

	while (*list_a != NULL)
	{	

		fill_up_posA(list_a);
		fill_up_posB(list_a, list_b);
		i = 0;
		j = find_minimum_cost(list_a);
		ds = *list_a;
		while (j > i++)
			ds = ds -> next;
		do_doble_movements(list_a, list_b, ds -> posA, ds -> posB);
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
	}
	do_doble_movements(list_a, list_b, 0, find_minimum(list_b));
	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
}
