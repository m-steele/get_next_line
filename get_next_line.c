#include <stdio.h>
#include "get_next_line.h"

char	*next_line(char **str, char *remain)
{
	char	*line;
	size_t	len;

	len = remain - *str + 1;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	sncopy(line, *str, len); /*custom strncpy()*/
	line[len] = '\0';
	*str = ft_strdup(remain + 1);
	return (line);
}

char	*last_line(char **str)
{
	char	*line;
	line = ft_strdup(*str);
	if (!line)
		return (NULL);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*remain;
	int			reader;

	if (!str)
 		str = ft_strdup("");
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!ft_strchr(str, '\n') && reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		buff[reader] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (!str[0])
		return (0);
	remain = ft_strchr(str, '\n');
	if (remain)
		// printf("remain = ft_strchr(str, ) =%s\n", remain);
		return (next_line(&str, remain));
	return (last_line(&str));
}

int main()
{
	int		fd;
	char	*line;
	int		lns;

	lns = 0;
	fd = open("test2.txt", O_RDONLY);
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
