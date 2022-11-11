/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:41:04 by ubegona           #+#    #+#             */
/*   Updated: 2022/11/11 10:28:38 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		while (s[i] != c && s[i])
			i++;
		if (s[i])
			i++;
	}
	return (len);
}

int	contletter(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s);
	j = 0;
	if (len <= i)
		p = malloc(len + 1);
	else
		p = malloc(i + 1);
	if (p == 0)
		return (NULL);
	while (start + j < i && j < len)
	{
		p[j] = s[start + j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (contword(s, c) + 1));
	if (split == 0)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		split[j] = ft_substr(s, i, contletter(&s[i], c));
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}
