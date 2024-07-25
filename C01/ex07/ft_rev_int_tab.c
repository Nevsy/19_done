/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:43 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/03 10:10:01 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/*#include <stdio.h>
int	main(void)
{
	int	tab[15] = {-1, 1100, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int	tab1[14] = {-1, 1100, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	int	i = 0;

	ft_rev_int_tab(tab, 15);
	ft_rev_int_tab(tab1, 14);
	while (i < 15)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 14)
	{
		printf("%d ", tab1[i]);
		i++;
	}
	return (0);
}*/