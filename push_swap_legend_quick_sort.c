/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_legend_quick_sort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:24:59 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/04 16:30:33 by ubegona          ###   ########.fr       */
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

void	fill_up_posA(t_list **list_a, t_list **list_b)
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
	while (i < len)
	{
		i++;
		if (ds -> content > c)
		{
			// printf("kaixo, content %d eta c %d----", ds -> content, c);
			pos = i;
		}	
		ds = ds -> next;
		
	}
	// printf("pos==%d\n", pos);
	if (pos > len / 2 && len != 1)
	{
		// printf("a ver");
		return (pos - len - 1);
	}
	else
		return(pos);
}

int	absolut(int c)
{
	if (c < 0)
		return (-1*c);
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
	printf(" **************************hau minimisimoa da %d\n", minimo);
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

		fill_up_posA(list_a, list_b);
		fill_up_posB(list_a, list_b);
		printf("hau a da AAAAAAAAAAAAAAAAAAAAAAAAA\n");
		printf_list(list_a);
		printf("Hau B da BBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
		printf_list(list_b);	
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
		// printf("zenbat da posB %d", posB);
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
		while (i < posB)
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
			swap_a(list_b);
		write(1, "sb\n", 3);
	}

	while (*list_b != NULL)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
}