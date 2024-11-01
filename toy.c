#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

// read(fd, void buf, int)
//Flags for open() function
// O_RDONLY		Open for reading only
// O_WRONLY		Open for writing only
// O_RDWR		Open for reading and writing
// O_CREAT		Create file if it doesn't exist
// O_APPEND		Append on each write
// O_DIRECTORY	Open a directory
// O_CLOEXEC	Close the file descriptor upon execution of an exec family function
// O_EXCL		Ensure that this call creates the file: if this flag is specified in conjunction with O_CREAT, and pathname already exists, then open() will fail

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s++)
		;
	return (s - str - 1);
}

char	*ft_join(const char *s1, const char *s2)
{
	char	*str;
	char	*jn;
	
	jn = (char *)malloc(length(s1) + length(s2) + 1);
	if (!jn)
		return (0);
	str = jn;
	while (*s1)
		*jn++ = *s1++;
	while (*s2)
		*jn++ = *s2++;
	*jn = '\0';
	return (str);
}

void ft()
{	static int	x = 0;
	x += 	printf("Size x: %i\n", x);
	// read(0, buffer, sizeof(buffer));
}

int main()
{
	ssize_t bytesRead;
	int fd = open("test2.txt", O_RDONLY);
	printf("Value of fd: %i\n\n", fd);
	// printf("%i\n", length(fd));
	if (fd == -1)
		{
			perror("ERROR opening file");
			return (1);
		}
	char buff[	42	];
	// while ((bytesRead = read(fd, buff, length(buff) - 1)) > 0)
	while ((bytesRead = read(fd, buff, sizeof(buff) - 1)) > 0)
	// bytesRead = read(fd, buff, sizeof(buff) - 1);
	{
		printf("bytesRead: %li\n", bytesRead);
		buff[bytesRead] = '\0';
		printf("%s\n\n", buff);
	}
	if (bytesRead == -1)
	{
		perror("ERROR reading file");
		return (1);
	}

	close(fd);
	return (0);
}


// This was used to understand how static variables work
// int main()
// {		char new[]= "Clowning Around";
// 	int	n = 5;
// // ft() --> captures num of chars, including "Size of 'A' ...
// 	ft(printf("Size of 'A': %i\n", n)); 
// 	n += write(1, &new, n)/2;
// 	printf("\n\n");
// 	// printf("\nTRACKER\n");
// 	ft(printf("Size of 'A' after 1: %i\n", n));
// 	n = write(1, &new, n);
// 	ft(printf("\n\n"));
// 	printf("Size of 'A' at end: %i\n", n);
// 		printf("\n\n");
// 	return (0);
// 	}
