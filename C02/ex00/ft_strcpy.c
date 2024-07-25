/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:43:02 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 11:15:31 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char src[] = "Hello, world!";
	char dest[50];

	ft_strcpy(dest, src);

	printf("Source string: %s\n", src);
	printf("Destination string: %s", dest);

	return 0;
}*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
