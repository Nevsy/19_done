/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:57:55 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 17:26:11 by sroyer           ###   ########.fr       */
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

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	**tab;
	char	*a;
	char	*b;

	a = "Hello";
	b = "world ";
	tab = malloc(sizeof(char *) * 3);
	tab[0] = a;
	tab[1] = b;
	tab[2] = NULL;
	printf("result: %d", ft_any(tab, &is_even));
	free(tab);
	return (0);
}*/