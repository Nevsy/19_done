/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:59:51 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 18:13:10 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char s11[12] = "hello ";
	char s12[12] = "hello ";
	char s2[5] = "world";
	
	printf("cat: %s\n", strcat(s11, s2));
	fflush(stdout);
	printf("ft: %s\n", ft_strcat(s12, s2));
	return (0);
}*/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_first;

	i = 0;
	len_first = 0;
	while (dest[len_first])
		len_first++;
	while (src[i])
	{
		dest[len_first + i] = src[i];
		i++;
	}
	dest[len_first + i] = '\0';
	return (dest);
}
