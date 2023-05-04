/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrakin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:38 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/17 13:29:06 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_track(char **tab, char c, int y, int x)
{
	if (tab[y][x] == '1' || (c != 'E' && tab[y][x] == 'E'))
		return (0);
	if (tab[y][x] == 'P')
		return (1);
	tab[y][x] = '1';
	if (check_track(tab, c, y + 1, x))
		return (1);
	if (check_track(tab, c, y - 1, x))
		return (1);
	if (check_track(tab, c, y, x + 1))
		return (1);
	if (check_track(tab, c, y, x - 1))
		return (1);
	return (0);
}

char	**copymap(char **s)
{
	int		i;
	int		l;
	char	**p;

	i = 0;
	l = -1;
	while (s[i])
		i++;
	p = malloc((i + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (++l < i)
		p[l] = ft_strdup(s[l]);
	p[l] = NULL;
	return (p);
}

void	backtrack2(char **copy, int j, int i)
{
	char	**test;

	while (copy[j][i])
	{
		if (copy[j][i] == 'C' || copy[j][i] == 'E')
		{
			test = copymap(copy);
			if (!check_track(test, test[j][i], j, i))
			{
				free_map(copy);
				free_map(test);
				write(1, "Error\nBack_track", 16);
				exit(1);
			}
			free_map(test);
		}
		i++;
	}
}

void	backtrack(t_data *data, char **copy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (copy[j][i] && j < data->h - 1)
	{
		backtrack2(copy, j, i);
		j++;
		i = 0;
	}
	free_map(copy);
}
