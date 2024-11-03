/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:42 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/31 13:05:26 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// THIS PASSES MOST OF THE TESTS; RUNS INTO PROBLEMS WITH:
// NULL CHECK ON MULTIPLE NEW LINES WHEN BUFF IS 10 AND 1000000

static void	get_line(int fd, char *buff, char **str)
{
	char	*temp;
	ssize_t	len;

	while ((!*str || !ft_strchr(*str, '\n')) && (len = read(fd, buff, BUFFER_SIZE)) > 0)
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
	free(buff);
}

// static void	get_line(int fd, char *buff, char **str)
// {
// 	char	*temp;
// 	size_t	len;

// 	if (!*str || !ft_strchr(*str, '\n'))
// 	{
// 		len = read(fd, buff, BUFFER_SIZE);
// 		while (len > 0)
// 		{
// 			buff[len] = '\0';
// 			if (!*str)
// 				*str = ft_substr(buff, 0, len);
// 			else
// 			{
// 				temp = *str;
// 				*str = ft_strjoin(*str, buff);
// 				free(temp);
// 			}
// 			// if (ft_strchr(buff, '\n'))
// 			// 	break ;
// 			len = read(fd, buff, BUFFER_SIZE);
// 		}
// 	}
// 	free(buff);
// }


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
		*str = ft_strdup(delim + 1); /* ft_substr(delim + 1, 0, ft_strlen(delim + 1));	*/
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

// static char	*return_line(char **str)
// {
// 	char	*line;
// 	char	*temp;
// 	char	*delim;
// 	size_t	len;
// 	size_t	nlen;

// 	if (!*str || !str)
// 		return (NULL);
// 	delim = ft_strchr(*str, '\n');
// 	len = ft_strlen(*str);
// 	if (!delim)
// 	{
// 		line = ft_substr(*str, 0, len);
// 		free (*str);
// 		*str = NULL;
// 		return (line);
// 	}
// 	nlen = ft_strlen(delim);
// 	line = ft_substr(*str, 0, len - nlen + 1);
// 	temp = *str;
// 	*str = ft_substr(delim, 1, nlen - 1);
// 	free(temp);
// 	return (line);
// }


// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*buff;

// 	if (fd < 0 || BUFFER_SIZE < 1 || !(buff = (char *)malloc(BUFFER_SIZE + 1)))
// 		return (NULL);
// 	get_line(fd, buff, &str);
// 	return (return_line(&str));
// }

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(buff);
		free(str);
		str = NULL;
		buff = NULL;
		return (NULL);
	}
	get_line(fd, buff, &str);
	return (return_line(&str));
}

// use this for viewing what is in *str at whatever location
// printf("\033[1;31m*str:\n%s\n\033[0m", *str);
// valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
// #include <stdio.h>
// int main()
// {
// 	int		fd;
// 	char	*line;
// 	int		lns;
// 	lns = 0;
// 	fd = open("testx.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		lns++;
// 		printf("Line%i: %s\n", lns, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
