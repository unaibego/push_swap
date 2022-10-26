/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:37:41 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/25 11:36:37 by ubegona          ###   ########.fr       */
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
	struct s_list	*next;
}					t_list;

#endif