/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:30:33 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 12:11:21 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(4));
	return (0);
}*/
