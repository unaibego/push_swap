/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:13:46 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/10 12:04:11 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_up_pos_a(t_list **list_a)
{
	t_list	*ds;
	float	len;
	int		i;

	ds = *list_a;
	len = ft_lstsize(*list_a);
	i = 0;
	while (i < len / 2)
	{
		ds -> pos_a = i;
		ds = ds -> next;
		i++;
	}
	while (ds != NULL)
	{
		ds -> pos_a = (len) / -2;
		ds = ds -> next;
		len = len - 2;
	}
}

void	fill_up_pos_b(t_list **list_a, t_list **list_b)
{
	t_list	*ds;
	int		minimo;
	int		len;

	ds = *list_a;
	minimo = ds -> content;
	len = ft_lstsize(*list_b);
	while (ds != NULL)
	{
		ds -> pos_b = find_position(0, len, ds -> content, list_b);
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
