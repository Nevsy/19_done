/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:24 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 10:35:48 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*test = "hello world!";
	char	*ft_test = ft_strdup(test);
	char	*real_test = strdup(test);
	printf("ft:\t%s\n", ft_test);
	printf("real:\t%s", real_test);
	free(ft_test);
	free(real_test);
	return (0);
}*/