/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:13:48 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/10 11:06:01 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_dbl_movements(t_list **list_a, t_list **list_b, int pos_a, int pos_b)
{
	while (pos_a < 0 && pos_b < 0)
	{
		rotate_down(list_a);
		rotate_down(list_b);
		write(1, "rrr\n", 4);
		pos_a++;
		pos_b++;
	}
	while (pos_a > 0 && pos_b > 0)
	{
		rotate_up(list_a);
		rotate_up(list_b);
		write(1, "rr\n", 3);
		pos_a--;
		pos_b--;
	}
	do_sgl_movements(list_a, list_b, pos_a, pos_b);
}

void	do_sgl_movements(t_list **list_a, t_list **list_b, int pos_a, int pos_b)
{
	while (pos_a < 0)
	{
		rotate_down(list_a);
		write(1, "rra\n", 4);
		pos_a++;
	}
	while (pos_a > 0)
	{
		rotate_up(list_a);
		write(1, "ra\n", 3);
		pos_a--;
	}
	while (pos_b < 0)
	{
		rotate_down(list_b);
		write(1, "rrb\n", 4);
		pos_b++;
	}
	while (pos_b > 0)
	{
		rotate_up(list_b);
		write(1, "rb\n", 3);
		pos_b--;
	}
}
