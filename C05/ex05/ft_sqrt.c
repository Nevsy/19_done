/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:44:14 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/17 09:48:50 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (nb / i > i)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(43630 * 43630));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(4330 * 4330));
	printf("%d\n", ft_sqrt(4330 * 4330 + 1));
	printf("%d 1\n", ft_sqrt(1));
	printf("%d 0\n", ft_sqrt(0));
	printf("%d -32\n", ft_sqrt(-32));
	return (0);
}*/