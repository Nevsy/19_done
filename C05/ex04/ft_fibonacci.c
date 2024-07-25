/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:31:52 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/15 16:27:51 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibo_next(int prev1, int prev2, int depth, int index)
{
	if (depth == index)
		return (prev1 + prev2);
	return (ft_fibo_next(prev2, prev1 + prev2, depth + 1, index));
}

int	ft_fibonacci(int index)
{
	int	result;

	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index < 0)
		return (-1);
	result = ft_fibo_next(0, 1, 2, index);
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_fibonacci(-9));
	printf("%d", ft_fibonacci(12));
	return (0);
}*/

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
// 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11,  12
