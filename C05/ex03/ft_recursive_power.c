/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:31:35 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 16:20:54 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power != 0)
		result = nb * ft_recursive_power(nb, power - 1);
	else
		return (result);
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_recursive_power(-8, 7));
	printf("%d", ft_recursive_power(0, 0));
	return 0;
}*/
