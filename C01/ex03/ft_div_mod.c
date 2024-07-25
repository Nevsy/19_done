/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:01 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/03 10:09:03 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
int	main(void)
{
	int a = 21;
	int b = 5;
	int div, mod;

	ft_div_mod(a, b, &div, &mod);
	printf("result: %i, modulo: %i", div, mod); // 4, 1
	return 0;
}*/