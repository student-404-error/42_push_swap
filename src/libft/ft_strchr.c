/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:50:59 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/22 11:03:57 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (c > 255)
		c -= 256;
	if (!*s && !c)
		return ((char *)s);
	while (*s && *s != c)
		s++;
	if ((char) c == '\0')
		return ((char *)s);
	if (!*s)
		return (NULL);
	return ((char *)s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char		str2[] = "bonjour";
	printf("%c\n", 'e' + 512);
	printf("%c\n", 'e');
	printf("%s\n", strchr("teste", 'e' + 256));
	printf("%s\n", ft_strchr("teste", 'e' + 256));
}*/
