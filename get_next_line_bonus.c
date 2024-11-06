/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:58 by ekosnick          #+#    #+#             */
/*   Updated: 2024/11/06 15:28:26 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	get_line(int fd, char *buff, char **str[fd])
{
	char	*temp;
	ssize_t	len;

	while (!*str[fd] || !ft_strchr(*str[fd], '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len > 0)
		{
			buff[len] = '\0';
			if (!*str[fd])
				*str[fd] = ft_strdup(buff);
			else
			{
				temp = *str[fd];
				*str[fd] = ft_strjoin(*str[fd], buff);
				free(temp);
			}
		}
		else
			break ;
	}
}

static char	*call_line(char *delim, char ***str[fd])
{
	char	*temp;
	char	*line;

	line = ft_substr(**str[fd], 0, delim - **str[fd] + 1);
	if (!line)
	{
		free(**str[fd]);
		**str[fd] = NULL;
		return (NULL);
	}
	else
	{
		temp = **str[fd];
		**str[fd] = ft_strdup(delim + 1);
		free(temp);
	}
	return (line);
}

static char	*return_line(char **str[fd])
{
	char	*line;
	char	*delim;

	if (!*str[fd])
		return (NULL);
	delim = ft_strchr(*str[fd], '\n');
	if (!delim)
	{
		line = *str[fd];
		*str[fd] = NULL;
	}
	else
	{
		line = call_line(delim, &str[fd]);
		if (*str[fd] && **str[fd] == '\0')
		{
			free(*str[fd]);
			*str[fd] = NULL;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str[fd]), str[fd] = NULL, NULL);
	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(buff);
		free(str[fd]);
		str[fd] = NULL;
		buff = NULL;
		return (NULL);
	}
	get_line(fd, buff, &str[fd]);
	free (buff);
	return (return_line(&str[fd]));
}
