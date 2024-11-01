/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:42 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/11/01 10:34:49 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

// ssize_t read(fd, void buf, int)
static char	*read_line(int fd, char *str)
{
	char		*buff;
	char		*temp;
	ssize_t		tlen;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	tlen = read(fd, buff, BUFFER_SIZE);
	if (tlen <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[tlen] = '\0';
	temp = str;
	str = ft_strjoin(str, buff);
	free(temp);
	free (buff);
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*nlposit; /*next line position*/

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!str)
		str = ft_strdup("");
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	printf("\033[1;30mstr:%s\n\033[0m", str);

	nlposit = ft_strchr(str, '\n');
	printf("\033[1;31mnlposit:%s\n\033[0m", nlposit);
	if (nlposit)
	{
		*nlposit = '\0';
		line = ft_strdup(str);
		str = ft_strdup(nlposit + 1);
	}

	else
	{
		line = ft_strdup(str);
		free(str);
		str = NULL;
	}


	return (line);
	// return (return_line(str));
}

// use this for viewing what is in *str at whatever location
// printf("\033[1;31m*str:\n%s\n\033[0m", *str);
// valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
#include <stdio.h>
int main()
{
	int		fd;
	char	*line;
	int		lns;
	lns = 0;
	fd = open("testx.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		lns++;
		printf("Line%i: %s\n", lns, line);
		free(line);
	}
	close(fd);
	return (0);
}
