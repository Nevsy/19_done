/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:32:25 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 16:47:03 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (nb / i >= i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	printf("next prime of %d? %d\n", 10, ft_find_next_prime(10));
	printf("next prime of %d? %d\n", 31, ft_find_next_prime(31));
	printf("next prime of  %d? %d\n", 1, ft_find_next_prime(1));
	printf("next prime of  %d? %d\n", -73, ft_find_next_prime(-73));
	printf("next prime of  %d? %d\n", 140904, ft_find_next_prime(140904));
	printf("next prime of  %d? %d\n", 960, ft_find_next_prime(960));
	return (0);
}*/
