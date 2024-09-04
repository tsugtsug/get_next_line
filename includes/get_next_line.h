/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:15:00 by yokamura          #+#    #+#             */
/*   Updated: 2023/01/07 21:16:08 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_free(char **s);
size_t	ft_strlen(char *s);
int		ft_strrchr_nl(char *s);
char	*ft_strcpy(char *src, char *dest, int index);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
