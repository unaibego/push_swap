/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:58 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/26 13:38:59 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_list(t_list **lst);

void	addlast(int content, t_list **anterior)
{
	t_list	*siguiente;
	t_list	*ds;
	
	siguiente = (t_list *)malloc(sizeof(t_list));
	siguiente = anterior;
	while (ds -> next != NULL)
	{
		printf("a ver q hace\n");
		(*s) = (*anterior) -> next;
	}
	(*anterior) -> next = siguiente;
	siguiente -> content = content;
	siguiente -> next = NULL;
	printf_list(anterior);
}

void	make_list(int argc, char **input, t_list **primerelemento)
{
	int		i;

	(*primerelemento) -> content = input[1][0] - 48;
	(*primerelemento) -> next = NULL;
	i = 2;
	while (i < argc)
	{
		printf("zenbat doa input%d\n", input[i][0] - 48);
		addlast(input[i][0] - 48, primerelemento);
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
		printf("%d --> %d\n", i, ds->content);
		ds = ds ->next;
		i++;
	}
}

int list_is_sort(t_list *list_num)
{
	t_list	*ds;
	int		i;

	ds = list_num;
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

void swap_a(t_list **list_num)
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

void push_b(t_list **list_a, t_list **list_b)
{
	addlast((*list_a) -> content, list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = (t_list *)malloc(sizeof(t_list));
	list_b = (t_list *)malloc(sizeof(t_list));
	make_list(argc, argv, &list_a);
	make_list(argc, argv, &list_b);
	// swap_a(&list_a);
	// printf_list(&list_a);
	push_b(&list_a, &list_b);
	push_b(&list_a, &list_b);
	push_b(&list_a, &list_b);
	push_b(&list_a, &list_b);
	// printf("hau ordenatuta al dago %d\n", list_is_sort(list_a));
	// printf_list(list_b);
	return (0);
}
