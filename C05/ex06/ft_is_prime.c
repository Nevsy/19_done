/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:32:12 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 16:47:16 by sroyer           ###   ########.fr       */
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

/*#include <stdio.h>

int	main(void)
{
	printf("is %d a prime? %d\n", 10, ft_is_prime(10));
	printf("is %d a prime? %d\n", 13, ft_is_prime(13));
	printf("is %d a prime? %d\n", 31, ft_is_prime(31));
	printf("is %d  a prime? %d\n", 2, ft_is_prime(2));
	printf("is %d a prime? %d", 2345673, ft_is_prime(2345673));
	return (0);
}*/
