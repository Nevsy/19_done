/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:31 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/24 19:22:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"

void	draw_square(int **tab, t_settings *settings, t_point *big)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings->line_count)
	{
		j = 0;
		while (j < settings->column_count)
		{
			if (tab[i][j] == 0)
				ft_putchar(settings->obstacle);
			else if (i > (big->x - big->value) && i <= big->x
				&& j > (big->y - big->value) && j <= big->y)
				ft_putchar(settings->full);
			else
				ft_putchar(settings->empty);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
