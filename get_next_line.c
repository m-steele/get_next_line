/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:46:01 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/11/05 08:16:36 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				*str = ft_substr(buff, 0, len);
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

static char	*return_line(char **str)
{
	char	*line;
	char	*temp;
	char	*delim;

	if (!*str)
		return (NULL);
	delim = ft_strchr(*str, '\n');
	if (delim)
	{
		line = ft_substr(*str, 0, delim - *str + 1);
		temp = *str;
		*str = ft_strdup(delim + 1);
		free(temp);
		if (*str && **str == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		return (NULL);
	}
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(buff);
		free(str);
		str = NULL;
		buff = NULL;
		return (NULL);
	}
	get_line(fd, buff, &str);
	free (buff);
	return (return_line(&str));
}
