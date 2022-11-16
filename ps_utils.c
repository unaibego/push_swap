/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:58 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/15 12:43:59 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addlast(int content, t_list **anterior)
{
	t_list	*siguiente;
	t_list	*ds;

	siguiente = (t_list *)malloc(sizeof(t_list));
	siguiente -> content = content;
	siguiente -> next = NULL;
	ds = (*anterior);
	while (ds -> next != NULL)
	{
		ds = ds -> next;
	}
	ds -> next = siguiente;
}

int	list_is_sort(t_list **list_num)
{
	t_list	*ds;
	int		i;

	ds = *list_num;
	i = ds -> content;
	while (ds != NULL)
	{
		if (ds -> content < i)
			return (0);
		i = ds -> content;
		ds = ds ->next;
	}
	return (1);
}

int	ft_lstsize(t_list **lst)
{
	t_list	*ds;
	int		i;

	ds = *lst;
	i = 0;
	while (ds != NULL)
	{
		ds = ds ->next;
		i++;
	}
	return (i);
}

int	absolut(int c)
{
	if (c < 0)
		return (-1 * c);
	else
		return (c);
}

int	is_max_min(int c, t_list **list_b)
{
	if (is_min(c, list_b) || is_max(c, list_b))
		return (1);
	return (0);
}
