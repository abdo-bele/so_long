/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:27 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/09 15:58:28 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
	d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

static int	ft_estim(long n)
{
	size_t	estim;

	estim = 0;
	if (n < 0)
	{
		estim++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	isneg = 0;
	rtn = ft_gen(rtn, nbr, len, isneg);
	if (rtn == 0)
		return (0);
	return (rtn);
}
