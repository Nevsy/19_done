/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:32:12 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 16:33:47 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	compute_p1(float x, float result, float interval)
{
	float	diff;
	float	abs_diff;

	diff = result * result - x;
	if (diff >= 0)
		abs_diff = diff;
	else
		abs_diff = -diff;
	while (abs_diff > 1e-6)
	{
		interval = interval / 2;
		if (diff > 0)
			result -= interval;
		else
			result += interval;
		diff = result * result - x;
		if (diff >= 0)
			abs_diff = diff;
		else
			abs_diff = -diff;
	}
	return (result);
}

int	ft_sqrt(int nb)
{
	float	result;
	float	interval;
	float	x;

	x = nb;
	result = 0;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
	{
		result = (x - 1) / 2 + 1;
		interval = (x - 1) / 2;
		result = compute_p1(x, result, interval);
	}
	return (result);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i <= ft_sqrt(nb) + 1)
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
	printf("is %d  a prime? %d", 1, ft_is_prime(1));
	return (0);
}*/
