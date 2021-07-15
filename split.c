/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:15:08 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 10:15:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (NULL);
	k = ft_strlen((char *)s);
	i = 0;
	if (start > k)
		return (ft_strdup(""));
	if (!(a = (char *)malloc((sizeof(char) * (len + 1)))))
		return (0);
	while (i < start)
		i++;
	j = 0;
	while (s[i] && (len--))
	{
		a[j] = s[i];
		i++;
		j++;
	}
	a[j] = '\0';
	return ((char *)a);
}
static	size_t	ft_countw(char *s, char c)
{
	size_t	i;
	size_t	mm;
	size_t	cpt;

	mm = 1;
	cpt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			mm = 1;
		else if (mm == 1)
		{
			mm = 0;
			cpt++;
		}
		i++;
	}
	return (cpt);
}

static	size_t	ft_wlen(char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static	char	**ft_free(char **f, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(f[i++]);
	free(f);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		countw;
	size_t		l_count;
	size_t		j;
	char		**p;

	i = 0;
	j = 0;
	l_count = 0;
	countw = ft_countw((char *)s, c);
	p = (char **)malloc(sizeof(char *) * (countw + 1));
	while (i < countw)
	{
		while (s[j] == c)
			j++;
		l_count = ft_wlen((char *)s + j, c);
		p[i] = ft_substr(s, j, l_count);
		if (!p)
			return (ft_free(p, i));
		i++;
		j += l_count + 1;
	}
	p[countw] = NULL;
	return (p);
}
