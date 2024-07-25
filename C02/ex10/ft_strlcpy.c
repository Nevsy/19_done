/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:38 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 12:53:44 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_src;

	size_src = ft_strlen(src);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[++i] = '\0';
	return (size_src);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = ":rse";
	char	dest1[100];
	char	dest2[100];
	printf("%i, %s\n", ft_strlcpy(src, dest1, 2), dest1);
	printf("%lu, %s\n", strlcpy(src, dest2, 2), dest2);
	printf("%lu, %s\n", strlcpy(src, dest2, 2), dest2);
	return (0);
}*/
