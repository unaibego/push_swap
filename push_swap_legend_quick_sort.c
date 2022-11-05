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
		ds -> posA = (len) / 2;
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
	if (pos > len / 2)
	{
		// printf("a ver");
		return (pos - len - 1);
	}
		
	else
		return(pos);
}
