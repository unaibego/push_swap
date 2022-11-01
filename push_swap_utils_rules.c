/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:58 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/01 10:59:58 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addfirst(int content, t_list **anterior)
{
	t_list	*siguiente;
	t_list	*ds;

	siguiente = (t_list *)malloc(sizeof(t_list));
	siguiente -> content = content;
	siguiente -> next = NULL;
	ds = (*anterior);
	(*anterior) = siguiente;
	siguiente -> next = ds;
}

void	swap_a(t_list **list_num)
{
	t_list	*ds;
	t_list	*c;


	ds = *list_num;
	ds = ds -> next;
	c = ds -> next;
	(*list_num) -> next = c;
	ds -> next = *list_num;
	*list_num = ds;

}

void	rotate_up(t_list **list_a)
{
	t_list	*ds;
	t_list	*c;

	ds = *list_a;
	c = *list_a;
	(*list_a) = (*list_a) -> next;
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
	addfirst(ds -> content, list_a);
	c -> next = NULL;
}

void	push_b(t_list **list_a, t_list **list_b)
{
	if (*list_b != NULL)
		addfirst((*list_a) -> content, list_b);
	else
	{
		(*list_b) = (t_list *)malloc(sizeof(t_list));
		(*list_b) -> content = (*list_a) -> content;
		(*list_b) -> next = NULL;
	}
	(*list_a) = (*list_a) ->next;
}
