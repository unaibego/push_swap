/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:58 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/16 12:24:14 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list_num)
{
	t_list	*ds;
	t_list	*c;

	ds = *list_num;
	ds = ds -> next;
	c = ds -> next;
	(*list_num)-> next = c;
	ds -> next = *list_num;
	*list_num = ds;
}

void	rotate_up(t_list **list_a)
{
	t_list	*ds;
	t_list	*c;

	ds = *list_a;
	c = *list_a;
	(*list_a) = (*list_a)-> next;
	while (ds -> next != NULL)
	{
		ds = ds -> next;
	}
	ds -> next = c;
	c -> next = NULL;
}

void	rotate_down(t_list **list_a)
{
	t_list	*ds;
	t_list	*c;

	ds = *list_a;
	c = *list_a;
	while (ds -> next != NULL)
	{
		c = ds;
		ds = ds -> next;
	}
	ds -> next = *list_a;
	*list_a = ds;
	c -> next = NULL;
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*ds;

	ds = (*list_a);
	(*list_a) = (*list_a)->next;
	if (*list_b != NULL)
	{
		ds -> next = (*list_b);
		(*list_b) = ds;
	}
	else
	{
		(*list_b) = ds;
		(*list_b)-> next = NULL;
	}
}
