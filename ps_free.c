/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:07:47 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/16 11:36:12 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_doble_punt(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

void	free_list(t_list **list_a)
{
	t_list	*ds;

	while ((*list_a))
	{
		ds = (*list_a)-> next;
		free((*list_a));
		(*list_a) = ds;
	}
}
