/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:37:41 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/16 09:13:12 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "ctype.h"
# include "string.h"
# include "stdlib.h"

// ********************************* estruktura ********************************

typedef struct s_list
{
	int				content;
	int				pos_a;
	int				pos_b;
	struct s_list	*next;
}					t_list;

// ********************************* ps_buble ********************************
int			compare_first(t_list **list_a, t_list **list_b);
void		quick_sort_bubble(t_list **list_a, t_list **list_b);
void		bubble(t_list **list_a, t_list **list_b);
// ********************************* ps_error ********************************
long int	ft_atoi(const char *str);
int			same_input(int c, char **argv);
int			push_swap_errors(int start, int argc, char **argv);
// ********************************* ps_fill_up ******************************
void		fill_up_pos_a(t_list **list_a);
void		fill_up_pos_b(t_list **list_a, t_list **list_b);
int			tartekoa_da(t_list *aurrekoa, t_list *hurrengoa, int c);
int			is_max(int c, t_list **list_b);
int			is_min(int c, t_list **list_b);
// ********************************* ps_legend_quick_sort *********************
int			find_minimum(t_list **list_a);
int			find_maximum(t_list **list_a);
int			find_position(int pos, int len, int c, t_list **list_b);
int			find_minimum_cost(t_list **list_a);
void		legend_quick_sort(t_list **list_a, t_list **list_b);
// ********************************* ps_main *********************
void		printf_list(t_list **lst);
void		make_list(int start, int argc, char **input,
				t_list **primerelemento);
int			main(int argc, char **argv);
void		algorithm(t_list **list_a, t_list **list_b);
// ********************************* ps_movement *****************************
void		do_dbl_movements(t_list **list_a, t_list **list_b,
				int pos_a, int pos_b);
void		do_sgl_movements(t_list **list_a, t_list **list_b,
				int pos_a, int pos_b);
// ********************************* ps_quick_sort ***************************
void		quick_sort(t_list **list_a, t_list **list_b);
// ********************************* ps_utils_rules ***************************
void		addfirst(int content, t_list **anterior);
void		swap_a(t_list **list_num);
void		rotate_up(t_list **list_a);
void		rotate_down(t_list **list_a);
void		push_b(t_list **list_a, t_list **list_b);
// ********************************* ps_utils ***************************
void		addlast(int content, t_list **anterior);
int			list_is_sort(t_list **list_num);
int			ft_lstsize(t_list **lst);
int			absolut(int c);
int			is_max_min(int c, t_list **list_b);
// ********************************* ps_three_input ***************************
int			three_inputs(t_list **list_a, t_list **list_b);
int			find_maximum_three(t_list **list_a);
// ********************************* ps_five_input ***************************
void		five_inputs(t_list **list_a, t_list **list_b);
int			find_minimum_five(t_list **list_a);
// ********************************* ps_split ***************************
int			contletter(char const *s, char c);
int			contword(char const *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
// ********************************* ps_free ***************************
void		free_doble_punt(char **input);
void		free_list(t_list **list_a);

#endif