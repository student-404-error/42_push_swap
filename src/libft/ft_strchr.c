/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:50:59 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/24 15:02:04 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (c > 255)
		c -= 256;
	if (!*s && !c)
		return ((char *)s);
	while (*s && *s != c)
		s++;
	if ((char) c == '\0')
		return ((char *)s);
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
