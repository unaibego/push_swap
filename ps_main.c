/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:17:36 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/10 12:06:15 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_list(t_list **lst)
{
	t_list	*ds;
	int		i;

	ds = *lst;
	i = 0;
	while (ds != NULL)
	{
		printf("%d --> content==|%d|  pos_a==|%d| posB==|%d|\n", i, ds->content, ds->pos_a, ds->pos_b);
		ds = ds ->next;
		i++;
	}
}

void	make_list(int argc, char **input, t_list **primerelemento)
{
	int		i;

	if ((*primerelemento) == NULL)
		(*primerelemento) = (t_list *)malloc(sizeof(t_list));
	(*primerelemento)->content = ft_atoi(input[1]);
	(*primerelemento)->next = NULL;
	i = 2;
	while (i < argc)
	{
		addlast(ft_atoi(input[i]), primerelemento);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*list_c;

	if (push_swap_errors(argc, argv))
		return (0);
	make_list(argc, argv, &list_c);
	make_list(argc, argv, &list_a);
	// legend_quick_sort(&list_a, &list_b);
	bubble(&list_c, &list_b);
	// printf_list(&list_a);
	// printf("aurrekoa a da\n");
	// printf_list(&list_b);
	return (0);
}
