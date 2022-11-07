/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_legend_quick_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:24:59 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/07 18:15:59 by ubegona          ###   ########.fr       */
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

	ds = *list_a;
	minimo = ds -> content;
	while (ds != NULL)
	{
		ds -> posB = find_position(ds -> content, list_b);
		ds = ds -> next;
	}
}

int	tartekoa_da(t_list *lehenengoa, t_list *aurrekoa, t_list *hurrengoa, int c)
{
	if (hurrengoa == NULL)
	{
		if (c < lehenengoa -> content)
		{
			if (aurrekoa -> content > c && lehenengoa -> content < aurrekoa -> content)
			{
				return (1);
			}
		}
		return (0);
	}
	printf(" c====== %d hau hurrengoaren contenta da %d eta hau aurrekoarena %d\n", c , hurrengoa -> content, aurrekoa -> content);
	if (aurrekoa -> content > c)
	{
		if (hurrengoa -> content < c)
		{
			printf("fdasdfdfsa\n");
			return (1);
		}
	}
	if (aurrekoa -> content < c && hurrengoa -> content > c)
	{
		hurrengoa = hurrengoa -> next;
		aurrekoa = aurrekoa -> next;
		if (hurrengoa -> content > aurrekoa -> content)
		{
			printf("fdasdfewradsfasddfsa\n");
			return (1);
		}
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
	// printf("hau j==|%d| eta hau i==!%d|\n", j, i);
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
			// printf(" a vver que hostias es esta puuta mierda maxximoo==%d eta content==%d\n", maximo, ds -> content);
			maximo = ds -> content;
			j = i;
		}
		ds = ds -> next;
		i++;
	}
	// printf("hau j==|%d| eta hau i==!%d|\n", j, i);
	if (i / 2 < j && i != 1)
		return (j - i - 1);
	else
		return (j);
}

int	find_position(int c, t_list **list_b)
{
	t_list	*ds;
	int		len;
	int		i;
	int		pos;

	ds = *list_b;
	len = ft_lstsize(*list_b);
	i = 0;
	pos = 0;
	if ((*list_b) != NULL && is_max_min(c, list_b) )
	{
		// printf("c ====%d que cojones pasa hau minimoa da %d eta hau maximoa %d\n", c, find_minimum(list_b), find_maximum(list_b));
		if (absolut(find_minimum(list_b)) < absolut(find_maximum(list_b)))
			return (find_minimum(list_b));
		else
			return (find_maximum(list_b));
	}

	while (i < len)
	{
		i++;
		if (tartekoa_da(*list_b, ds, ds -> next, c))
		{
			pos = i;
			if (ds -> next == NULL)
				pos = 0;
			break ;
		}
		ds = ds -> next;
	}
	// printf("pos==%d\n", pos);
	if (pos > len / 2 && len != 1)
	{
		return (pos - len);
	}
	else
		return (pos);
}

int	absolut(int c)
{
	if (c < 0)
		return (-1 * c);
	else
		return (c);
}

int	find_minimum_legend(t_list **list_a)
{
	t_list	*ds;
	int		i;
	int		j;
	int		minimo;

	ds = *list_a;
	minimo = absolut(ds -> posA) + absolut(ds -> posB);
	// printf(" **************************hau minimisimoa da %d\n", minimo);
	j = 0;
	i = 0;
	while (ds != NULL)
	{
		if (minimo >  absolut(ds -> posA) + absolut(ds -> posB))
		{
			minimo = absolut(ds -> posA) + absolut(ds -> posB);
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
	int	posA;
	int	posB;
	int	i;
	int	j;

	while (*list_a != NULL)
	{	

		fill_up_posA(list_a);
		fill_up_posB(list_a, list_b);
		// printf("hau a da AAAAAAAAAAAAAAAAAAAAAAAAA\n");
		// printf_list(list_a);
		// printf("Hau B da BBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
		// printf_list(list_b);	
		i = 0;
		j = find_minimum_legend(list_a);
		ds = *list_a;
		// printf("ze hostiassssssssssssssssssssssss %d\n", j);
		while (i < j)
		{
			ds = ds -> next;
			i++;
		}
		posA =  ds -> posA;
		posB =  ds -> posB;
		i = 0;
		while (i < posA)
		{
			rotate_up(list_a);
			write(1, "ra\n", 3);
			i++;
		}
		while (i > posA)
		{
			rotate_down(list_a);
			write(1, "rra\n", 4);
			i--;
		}
		i = 0;
		while (i < posB && posB != 1)
		{
			rotate_up(list_b);
			write(1, "rb\n", 3);
			i++;
		}
		while (i > posB)
		{
			rotate_down(list_b);
			write(1, "rrb\n", 4);
			i--;
		}
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
		if (posB == 1)
		{
			swap_a(list_b);
			write(1, "sb\n", 3);
		}

	}

	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
}
