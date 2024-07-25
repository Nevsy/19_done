/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:31:18 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 16:24:25 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power != 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(-8, 7));
	printf("%d", ft_iterative_power(0, 0));
	return 0;
}*/
