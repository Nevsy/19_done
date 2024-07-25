/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:59:59 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 18:12:14 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
	char s11[12] = "hello ";
	char s12[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %s\n", strncat(s11, s2, 4));
	fflush(stdout);
	printf("ft: %s\n", ft_strncat(s12, s2, 4));
	return (0);
}*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				len_dest;

	i = 0;
	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while (src[i] != '\0' && i < nb)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}
