/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:50:36 by preina-g          #+#    #+#             */
/*   Updated: 2022/12/17 17:52:10 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_gnl_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src, int start);
char	*ft_read_line(int fd, char *file_rd);

#endif