/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_working_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:46:01 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/11/08 09:13:40 by peatjohnsto      ###   ########.fr       */
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

static char	*return_line(char **str)
{
	char	*line;
	char	*temp;
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
		line = ft_substr(*str, 0, delim - *str + 1);
		if (!line)
			return (free(*str), *str = NULL, NULL);
		temp = *str;
		*str = ft_strdup(delim + 1);
		free(temp);
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
	static char	*str;
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(buff);
		free(str);
		str = NULL;
		buff = NULL;
		return (NULL);
	}
	get_line(fd, buff, &str);
	free (buff); /*--> this was the issue, only need to free *str after read*/
	return (return_line(&str));
}


// This is Frenec's version that worked and is 
// similar to mine. Looking for a way to free
// free memory and protect after the read....

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *) s);
}

static char	*fill_stash(int fd, char *stash, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(stash), free(buffer), NULL);
		buffer[b_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*set_line(char *stash)
{
	char	*line;
	char	*new_line;
	ssize_t	i;

	i = 0;
	line = NULL;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	new_line = ft_substr(stash, 0, i + (stash[i] == '\n'));
	if (new_line)
		line = malloc((ft_strlen(new_line) + 1) * sizeof(char));
	if (!line)
		return (free(new_line), NULL);
	i = -1;
	while (new_line[++i])
		line[i] = new_line[i];
	line[i] = '\0';
	free(new_line);
	return (line);
}

static char	*shift_stash(char *stash, size_t len)
{
	char	*new_stash;
	size_t	stash_len;

	if (!stash || !*stash)
		return (NULL);
	stash_len = ft_strlen(stash);
	if (len >= stash_len)
		return (NULL);
	new_stash = ft_substr(stash, len, stash_len - len);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_stash;
	char		*line;
	char		*buffer;

	new_stash = NULL;
	line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), stash = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	stash = fill_stash(fd, stash, buffer);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	new_stash = shift_stash(stash, ft_strlen(line));
	free(stash);
	stash = new_stash;
	return (line);
}