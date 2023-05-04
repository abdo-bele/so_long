/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:15:43 by aarchtou          #+#    #+#             */
/*   Updated: 2023/02/17 13:54:32 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	int			fd;
	int			w;
	int			h;
	int			y_p;
	int			x_p;
	int			count;
	int			khtawi;
	int			pl;
	int			ex;
	char		*path;
	char		**map;
	void		*img;
	void		*mlx;
	void		*win;
	void		*mur;
	void		*enmi;
	void		*exite;
	void		*player;
	void		*ground;
	void		*colect;
}				t_data;

int		up(t_data	*data);
int		l(t_data	*data);
int		r(t_data	*data);
int		down(t_data	*data);
void	free_map(char **map);
int		draw_map(t_data *data);
void	parsing2(t_data	*data);
char	*ft_itoa(int n);
void	check_collect(t_data *data);
void	ft_check_data(t_data *data);
void	parcing_b(t_data *data, int ac);
char	**ft_split(char const *s, char c);
int		ft_check_collect_number(t_data *data);
void	chek_pl_ex(char	*ab, t_data *data);
int		ft_exit(int keycode, t_data *data);
void	backtrack(t_data *s_data, char **copy);
char	*ft_strjoinn(char const *s1, char const *s2);

#endif