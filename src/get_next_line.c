/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:00 by yokamura          #+#    #+#             */
/*   Updated: 2023/01/10 20:05:28 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_rest(char *rest, int fd)
{
	char	*buffer;
	ssize_t	rb;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	rb = 1;
	while ((ft_strrchr_nl(rest)) == -1 && rb != 0)
	{
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb == -1)
		{
			ft_free(&buffer);
			return (NULL);
		}
		buffer[rb] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	ft_free(&buffer);
	return (rest);
}

static char	*ft_rest_to_str(char *rest)
{
	char	*str;

	if (rest == NULL || rest[0] == '\0')
	{
		ft_free(&rest);
		return (NULL);
	}
	if (ft_strrchr_nl(rest) == -1)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(rest) + 1));
		if (str == NULL)
			return (NULL);
		str = ft_strcpy(rest, str, ft_strlen(rest));
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (ft_strrchr_nl(rest) + 2));
		if (str == NULL)
			return (NULL);
		str = ft_strcpy(rest, str, ft_strrchr_nl(rest) + 1);
	}
	return (str);
}

static char	*ft_update_rest(char *rest)
{
	char	*new_rest;
	int		index_nl;
	int		len;
	int		i;

	index_nl = ft_strrchr_nl(rest);
	new_rest = NULL;
	if (index_nl != -1)
	{
		len = ft_strlen(rest);
		new_rest = (char *)malloc(sizeof(char) * (len - index_nl + 1));
		if (new_rest == NULL)
		{
			ft_free(&rest);
			return (NULL);
		}
		index_nl++;
		i = 0;
		while (index_nl < len)
			new_rest[i++] = rest[index_nl++];
		new_rest[i] = '\0';
	}
	ft_free(&rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*rest;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	str = NULL;
	rest = ft_read_to_rest(rest, fd);
	if (rest == NULL)
		return (NULL);
	str = ft_rest_to_str(rest);
	if (str == NULL)
	{
		rest = NULL;
		return (NULL);
	}
	rest = ft_update_rest(rest);
	return (str);
}
