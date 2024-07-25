/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:40:35 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 17:26:07 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int is_even(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i % 2 == 0)
		return (1);
	return (0);
}*/

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	**tab;
	char	*a;
	char	*b;

	a = "Hello ";
	b = "world ";
	tab = malloc(sizeof(char *) * 3);
	tab[0] = a;
	tab[1] = b;
	tab[2] = NULL;
	printf("result: %d", ft_count_if(tab, &is_even));
	free(tab);
	return (0);
}*/