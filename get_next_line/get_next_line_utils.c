/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:22:59 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/07 22:40:23 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*ptr;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
		ptr[l++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[l++] = s2[i++];
	ptr[l] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_get_next_line(char	*abdo)
{
	char	*ab;
	int		i;
	int		a;

	i = 0;
	while (abdo[i] && abdo[i] != '\n')
		i++;
	if (!abdo[i])
	{
		free(abdo);
		return (NULL);
	}
	ab = malloc(ft_strlen(abdo) - i + 1);
	if (!ab)
		return (free(abdo), NULL);
	i++;
	a = 0;
	while (abdo[i])
		ab[a++] = abdo[i++];
	ab[a] = '\0';
	free(abdo);
	return (ab);
}

char	*ft_get_line(char *abdo)
{
	char	*ab;
	int		i;

	i = 0;
	if (!abdo[i])
		return (NULL);
	while (abdo[i] && abdo[i] != '\n')
		i++;
	ab = malloc(i + 2);
	i = 0;
	while (abdo[i] && abdo[i] != '\n')
	{
		ab[i] = abdo[i];
		i++;
	}
	if (abdo[i] == '\n')
	{
		ab[i] = abdo[i];
		i++;
	}
	ab[i] = '\0';
	return (ab);
}
