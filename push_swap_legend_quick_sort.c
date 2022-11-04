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
	int		len;

	ds = *list_a;
	len = ft_lstsize(list_a);
	i = 0;
	while (i < len / 2)
	{
		ds -> posA = i;
		ds = ds -> next;
		i++;
	}
	while (ds != NULL)
	{
		ds -> posA = (len - 0.5) / 2;
		ds = ds -> next;
		len--;
	}

}

void	fill_up_posB(t_list **list_a, t_list	**list_b)
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

		ds = ds -> next;
		i++;
	}
	if (i * 3 / 4 < j)
		return (j - i);
	else
		return (j);
}

void	find_position(int c, t_list **list_a)
{
	t_list	*ds;
	int		len; 

	ds = *list_a;
	len = ft_lstsize(list_a);
	while (i < len / 2)
	{
		ds -> posA = i;
		ds = ds -> next;
		i++;
	}
}
