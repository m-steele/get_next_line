/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:58 by ekosnick          #+#    #+#             */
/*   Updated: 2024/11/07 10:38:03 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "get_next_line_bonus.h"

static void	get_line(int fd, char *buff, char **str)
{
	char	*temp;
	ssize_t	len;

	while (!*str || !ft_strchr(*str, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len > 0)
		{
			buff[len] = '\0';
			if (!*str)
				*str = ft_strdup(buff);
			else
			{
				temp = *str;
				*str = ft_strjoin(*str, buff);
				free(temp);
			}
		}
		else
			break ;
	}
}

static char	*call_line(char *delim, char ***str)
{
	char	*temp;
	char	*line;

	line = ft_substr(**str, 0, delim - **str + 1);
	if (!line)
		return (free(**str), **str = NULL, NULL);
	temp = **str;
	**str = ft_strdup(delim + 1);
	free(temp);
	return (line);
}

static char	*return_line(char **str)
{
	char	*line;
	char	*delim;

	if (!*str)
		return (NULL);
	delim = ft_strchr(*str, '\n');
	if (!delim)
	{
		line = *str;
		*str = NULL;
	}
	else
	{
		line = call_line(delim, &str);
		if (*str && **str == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_FD];
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str[fd]), str[fd] = NULL, NULL);
	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (free(str[fd]), free(buff), buff = NULL, str[fd] = NULL, NULL);
	get_line(fd, buff, &str[fd]);
	free (buff);
	return (return_line(&str[fd]));
}
