/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:04:29 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/23 15:40:34 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

char	*ft_join(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);/*memcpy() length()*/
size_t	ft_strlcat(char *dst, char *src, size_t size); /*memcpy() length()*/

#endif