/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:31:01 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 12:13:10 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb != 0)
		result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_factorial(4));
	return (0);
}*/
