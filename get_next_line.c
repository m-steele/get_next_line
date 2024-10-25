#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*build;
	void		*buf;
	char		*gnl;
	size_t		nbyte;

	read(fd, buf, nbyte = ft_strlen(fd));

	gnl = ft_strchr(buf, nbyte);

}