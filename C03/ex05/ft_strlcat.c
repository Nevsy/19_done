/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:00:08 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 09:42:47 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
	char s11[12] = "hello ";
	char s12[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %lu\n", strlcat(s11, s2, 9));
	fflush(stdout);
	printf("ft: %d\n", ft_strlcat(s12, s2, 9));
	return (0);
}*/

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	if (size == 0 || size <= len_dest)
		return (len_src + size);
	while (src[i] && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
