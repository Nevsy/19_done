/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:01:57 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/24 18:25:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_functions.h"
#include <stdio.h>

int	new_nbr(int left, int up, int diag)
{
	int	small;

	small = left;
	if (up <= left && up <= diag)
		small = up;
	if (diag <= up && diag <= left)
		small = diag;
	return (small + 1);
}

void	modify_square(int **tab, t_settings *settings)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings->line_count)
	{
		j = 0;
		while (j < settings->column_count)
		{
			if (tab[i][j] != 0 && i != 0 && j != 0)
			{
				tab[i][j] = new_nbr(tab[i - 1][j],
						tab[i][j - 1], tab[i - 1][j - 1]);
			}
			if (tab[i][j] > settings->big->value)
			{
				settings->big->x = i;
				settings->big->y = j;
				settings->big->value = tab[i][j];
			}
			j++;
		}
		i++;
	}
}
