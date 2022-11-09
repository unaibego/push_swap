/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:58 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/09 13:29:32 by ubegona          ###   ########.fr       */
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
		// printf("zenbat doa resul %d\n", resul);
		i++;
	}
	return (resul * minus);
}

void	addlast(int content, t_list **anterior)
{
	t_list	*siguiente;
	t_list	*ds;

	siguiente = (t_list *)malloc(sizeof(t_list));
	siguiente -> content = content;
	siguiente -> next = NULL;
	ds = (*anterior);
	while (ds -> next != NULL)
	{
		ds = ds -> next;
	}
	ds -> next = siguiente;
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

void	printf_list(t_list **lst)
{
	t_list	*ds;
	int		i;

	ds = *lst;
	i = 0;
	while (ds != NULL)
	{
		printf("%d --> content==|%d|  posA==|%d| posB==|%d|\n", i, ds->content, ds->posA, ds->posB);
		ds = ds ->next;
		i++;
	}
}

int	list_is_sort(t_list **list_num)
{
	t_list	*ds;
	int		i;

	ds = *list_num;
	i = ds -> content;
	while (ds != NULL)
	{
		if (ds -> content < i)
			return (0);
		i = ds -> content;
		ds = ds ->next;
	}
	return (1);
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
	// legend_quick_sort(&list_a,  &list_b);
	bubble(&list_c, &list_b);
	// printf_list(&list_a);
	// printf("aurrekoa a da\n");
	// printf_list(&list_b);

	return (0);
}
