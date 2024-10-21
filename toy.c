#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
void ft()
{	static int	x = 0;
	x++;
	printf("Size From ft(): %i\n", x);}

int main()
{	char new[]= "Clowning Around";
	char	*s;
	int		n = strlen(new);
	s = new;
	ft(printf("Size of 'A': %i\n", n));
	while (s)
	{
	n -= write(1, &s, n)/2;
	printf("\n\n");
	}
	n += write(1, &new, n)/2;
	printf("\n\n");
	// printf("\nTRACKER\n");
	ft(printf("Size of 'A' after 1: %i\n", n));
	n = write(1, &new, n);
	ft(printf("\n\n"));
	ft(printf("Size of 'A' after 2: %i\n", n));
	n = write(1, &new, n);
	ft(printf("\n\n"));
	ft(printf("Size of 'A' after 3: %i\n", n));
	n = write(1, &new, n);
	ft(printf("\n\n"));
	// printf("Original: %s\nThe Copy3: %ld\n", new, n3);
	printf("Size of 'A' at end: %i\n", n);
		printf("\n\n");
	return (0);
	}

// int main()
// {	char new[] = "Clowning Around";
// 	size_t		n1;
// 	size_t 		n2;
// 	size_t 		n3;
// 	size_t 		n4;
// 	int			a = 5;
// 	ft(printf("Size of 'A' before 1: %i\n", a));
// 	n1 = write(1, &new, a); 	a+=a/2;
// 	printf("\n\n");
// 	ft(printf("Size of 'A' after 1: %i\n", a));
// 	n2 = write(1, &new, a); 	a+=a/2;
// 	ft(printf("\n\n"));
// 	ft(printf("Size of 'A' after 2: %i\n", a));
// 	n3 = write(1, &new, a); 	a+=a/2;
// 	ft(printf("\n\n"));
// 	ft(printf("Size of 'A' after 3: %i\n", a));
// 	n3 = write(1, &new, a);
// 	ft(printf("\n\n"));
// 	printf("Size of 'A' at end: %i\n", a);
// 		printf("\n\n");
// 	return (0);
// 	}