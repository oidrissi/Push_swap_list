/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:32:13 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 10:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "push_swap.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*v;
	const char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (NULL);
	v = (char *)dst;
	s = (const char *)src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
		*v++ = *s++;
	return (dst);
}

char		*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * i);
	return (ptr ? ft_memcpy(ptr, s, i) : NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((!s1 && !s2) || !s1)
		return (0);
	if (!(p = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i++] = s2[j];
		j++;
	}
	p[i] = '\0';
	return (p);
}
