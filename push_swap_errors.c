/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:39:38 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/07 15:31:19 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int same_input(int c, char **argv)
{
	int j;

	j = 1;
	while (argv[j])
	{
		if (c == ft_atoi(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int push_swap_errors(int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	if (argc < 2)
		return (1);
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9') && argv[j][i] != '-' )
			{
				write(1, "Error\n", 6);
				return (1);
			}
			i++;
		}
		// printf("zebbat da hau %d", ft_atoi(argv[j]));
		if ((ft_atoi(argv[j]) > 2147483647) || same_input(ft_atoi(argv[j]), &argv[j]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}