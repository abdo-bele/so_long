/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:18:46 by aarchtou          #+#    #+#             */
/*   Updated: 2023/01/25 12:22:46 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 1

size_t	ft_strlen(const char *c);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *abdo);
char	*ft_get_next_line(char	*abdo);

#endif