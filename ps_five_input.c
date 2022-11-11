/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_five_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:55:26 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/11 11:50:50 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_inputs(t_list **list_a, t_list **list_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		do_dbl_movements(list_a, list_b, find_minimum_five(list_a), 0);
		push_b(list_a, list_b);
		write(1, "pb\n", 3);
		i++;
	}
	three_inputs(list_a, list_b);
	i = 0;
	while (i < 2)
	{
		push_b(list_b, list_a);
		write(1, "pa\n", 3);
		i++;
	}
}
