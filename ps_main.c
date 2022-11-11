/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:17:36 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/11 11:47:33 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printf_list(t_list **lst)
// {
// 	t_list	*ds;
// 	int		i;

// 	ds = *lst;
// 	i = 0;
// 	while (ds != NULL)
// 	{
// 	    printf("%d --> content==|%d|  \n", i, ds->content);
// 		ds = ds ->next;
// 		i++;
// 	}
// }

void	make_list(int start, int argc, char **input, t_list **primerelemento)
{
	int		i;

	if ((*primerelemento) == NULL)
		(*primerelemento) = (t_list *)malloc(sizeof(t_list));
	(*primerelemento)->content = ft_atoi(input[start]);
	(*primerelemento)->next = NULL;
	i = start + 1;
	while (i < argc)
	{
		addlast(ft_atoi(input[i]), primerelemento);
		i++;
	}
}

void	algorithm(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) == 3)
		three_inputs(list_a, list_b);
	if (ft_lstsize(*list_a) == 5)
		five_inputs(list_a, list_b);
	else if (ft_lstsize(*list_a) != 3)
		legend_quick_sort(list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**input;
	int		i;

	i = 0;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		while (input[i])
			i++;
		if (i == 1)
			return (0);
		make_list(0, i, input, &list_a);
		if (push_swap_errors(0, i, input))
			return (0);
	}
	else
	{
		make_list(1, argc, argv, &list_a);
		if (push_swap_errors(1, argc, argv))
			return (0);
	}
	algorithm(&list_a, &list_b);
	return (0);
}
