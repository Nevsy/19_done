/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:40:35 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 17:26:00 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int compare(int x, int y)
{
	return (x - y);
}*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	int tab[] = {2, 6, 7, 32, 52, 100};
	printf("result: %d", ft_is_sort(tab, 6, &compare));
	return (0);
}*/