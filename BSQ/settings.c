/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:26:29 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 23:00:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"
#include <stdlib.h>

int	are_chars_valid(t_settings *settings)
{
	if (settings->empty == settings->full
		|| settings->empty == settings->obstacle
		|| settings->full == settings->obstacle)
	{
		ft_putstr("map error\n");
		return (0);
	}
	return (1);
}

int	are_lens_valid(t_settings *settings)
{
	if (settings->line_count <= 0
		|| settings->column_count <= 0)
	{
		ft_putstr("map error\n");
		return (0);
	}
	return (1);
}

void	*free_settings(t_settings *settings)
{
	int	i;

	i = 0;
	ft_putstr("map error\n");
	while (i < settings->line_count)
	{
		free(settings->map[i]);
		i++;
	}
	free(settings->map);
	free(settings);
	return (NULL);
}

void	*free_settings_until(t_settings *settings, int until)
{
	int	i;

	i = 0;
	ft_putstr("map error\n");
	while (i < settings->line_count && i < until)
	{
		free(settings->map[i]);
		i++;
	}
	free(settings->map);
	return (NULL);
}

void	*free_settings_main(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->line_count)
	{
		free(settings->map[i]);
		i++;
	}
	free(settings->map);
	return (NULL);
}
