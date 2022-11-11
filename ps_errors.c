/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:39:38 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/11 11:39:06 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	resul;
	int			minus;

	i = 0;
	resul = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		i++;
		minus = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			resul = resul * 10 + str[i] - '0';
		i++;
	}
	return (resul * minus);
}

int	same_input(int c, char **argv)
{
	int	start;

	start = 1;
	while (argv[start])
	{
		if (c == ft_atoi(argv[start]))
			return (1);
		start++;
	}
	return (0);
}

int	push_swap_errors(int start, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	while (argv[start])
	{
		i = -1;
		while (argv[start][++i])
		{
			if ((argv[start][i] < '0' || argv[start][i] > '9')
				&& argv[start][i] != '-' )
			{
				write(1, "Error\n", 6);
				return (1);
			}
		}
		if ((ft_atoi(argv[start]) > 2147483647)
			|| same_input(ft_atoi(argv[start]), &argv[start]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		start++;
	}
	return (0);
}
