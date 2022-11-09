/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:37:41 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/09 13:31:20 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "ctype.h"
# include "string.h"
# include "stdlib.h"

typedef struct s_list
{
	int				content;
	int				posA;
	int				posB;
	struct s_list	*next;
}					t_list;

void		addfirst(int content, t_list **anterior);
void		addlast(int content, t_list **anterior);
void		make_list(int argc, char **input, t_list **primerelemento);
void		printf_list(t_list **lst);
int			list_is_sort(t_list **list_num);
void		swap_a(t_list **list_num);
void		rotate_up(t_list **list_a);
void		rotate_down(t_list **list_a);
void		push_b(t_list **list_a, t_list **list_b);
int			compare_first(t_list **list_a, t_list **list_b);
void		bubble(t_list **list_a, t_list **list_b);
long int	ft_atoi(const char *str);
void		quick_sort(t_list **list_a, t_list **list_b);
int			find_minimum(t_list **list_a);
int			push_swap_errors(int argc, char **argv);
int			same_input(int c, char **argv);
int			ft_lstsize(t_list *lst);
void		fill_up_posA(t_list **list_a);
void		fill_up_posB(t_list **list_a, t_list **list_b);
int			find_position(int len, int c, t_list **list_b);
void		legend_quick_sort(t_list **list_a, t_list **list_b);
int			absolut(int c);
void		do_sgl_movements(t_list **list_a, t_list **list_b, int posA, int posB);
void		do_doble_movements(t_list **list_a, t_list **list_b, int posA, int posB);
int			find_minimums(t_list **list_a);

#endif