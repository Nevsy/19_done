/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:13 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/03 10:09:15 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*#include <stdio.h>
int	main(void)
{
	int a;
	int b;

	a = 21;
	b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf("result: %d, modulo: %d", a, b);
	return 0;
}*/