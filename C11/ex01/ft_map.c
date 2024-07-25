/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:57:55 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 10:23:44 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

int	add_one(int nb)
{
	return (nb + 1);
}*/

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		tab[i] = f(tab[i]);
		i++;
	}
	return (tab);
}

/*#include <stdio.h>
int	main(void)
{
	int tab[] = {5, 31, 72, 1, -32};
	ft_map(tab, 5, &add_one);
	for (int i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	return (0);
}*/