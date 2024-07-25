/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:27 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 09:50:04 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char s1[] = "hello world";
	char s2[] = "this is a longer string";

	printf("ft1: %d\n", ft_strlen(s1));
	printf("ft2: %d\n", ft_strlen(s2));
	printf("len1: %lu\n", strlen(s1));
	printf("len1: %lu\n", strlen(s2));
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
