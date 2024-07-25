/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:00:24 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 17:10:52 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_abs(long double x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

long double	compute_p1(long double x, long double result, long double interval)
{
	long double	diff;

	diff = result * result - x;
	while (ft_abs(diff) > 0.000000000001)
	{
		interval = interval / 2;
		if (diff > 0)
			result -= interval;
		else
			result += interval;
		diff = result * result - x;
	}
	return (result);
}

int	ft_sqrt(int nb)
{
	long double	result;
	int			result_int;
	long double	rest;
	long double	interval;
	long double	x;

	result = 0;
	x = nb;
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
	result_int = result;
	rest = result - result_int;
	if (rest == 0)
		return (result_int);
	if (rest > 0.9999999999)
		return (result_int + 1);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(157 * 157));
	printf("%d\n", ft_sqrt(16000001)); // 0
	printf("%d\n", ft_sqrt(16000000)); // 4000
	printf("%d\n", ft_sqrt(2147483647)); // 0 -> max int
	printf("%d min int\n", ft_sqrt(-2147483648)); // 0 -> max int
	printf("%d\n", ft_sqrt(46340 * 46340));
	printf("%d max + 1\n", ft_sqrt(46340 * 46340 + 1));
	printf("%d\n", ft_sqrt(2)); // 0
	printf("%d\n", ft_sqrt(0)); // 0
	printf("%d\n", ft_sqrt(25)); // 5
	printf("%d\n", ft_sqrt(-17)); // 0
	return (0);
}
