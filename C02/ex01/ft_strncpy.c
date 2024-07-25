/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:43:14 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 14:50:19 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	char src[] = "Hello world";
	char dest1[11];
	char dest2[11];
	printf("Source string: %s\n", src);
	
	ft_strncpy(dest1, src, 10);
	printf("Destination string: %s\n", dest1);

	strncpy(dest2, src, 10);
	printf("Destination string: %s\n", dest2);

	return (0);
}*/

unsigned int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
