/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:21 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 23:06:30 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_functions.h"

void	*throw_map_error(t_settings *settings, int line_count)
{
	if (line_count < 0)
	{
		ft_putstr("map error\n");
		exit(1);
	}
	else
	{
		free_settings_until(settings, line_count);
		exit(1);
	}
	return (NULL);
}

void	get_chars_in_settings(char *buff, t_settings *settings, int index)
{
	settings->full = buff[index - 1];
	settings->obstacle = buff[index - 2];
	settings->empty = buff[index - 3];
	are_chars_valid_stdin(settings);
}

t_settings	*parse_settings_stdin(char *buff)
{
	int			i;
	int			j;
	t_settings	*settings;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	settings = malloc(sizeof(t_settings));
	if (i < 4)
		throw_map_error(settings, -1);
	get_chars_in_settings(buff, settings, i);
	j = -1;
	settings->line_count = 0;
	while (++j < i - 3)
	{
		if (settings->line_count > 214748360)
			throw_map_error(settings, -1);
		settings->line_count = 10 * settings->line_count + (buff[j] - '0');
	}
	if (settings->line_count < 1)
		return (throw_map_error(settings, -1));
	settings->column_count = -1;
	return (settings);
}

int	*parse_line_stdin(char buffer[10000], t_settings *settings, int line)
{
	int	i;
	int	*map_line;

	i = 0;
	while (buffer[i] != '\n' || !buffer[i])
		i++;
	if ((settings->column_count != -1 && settings->column_count != i) || i == 0)
		return (throw_map_error(settings, line));
	settings->column_count = i;
	map_line = malloc(sizeof(int) * i);
	if (!map_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == settings->empty)
			map_line[i] = 1;
		else if (buffer[i] == settings->obstacle)
			map_line[i] = 0;
		else
			return (throw_map_error(settings, line));
		i++;
	}
	return (map_line);
}

t_settings	*parse_stdin(void)
{
	char		buffer[10000];
	int			nb;
	int			i;
	t_settings	*settings;

	nb = read(0, buffer, 9999);
	if (nb <= 0)
		throw_map_error(NULL, -1);
	settings = parse_settings_stdin(buffer);
	if (!settings)
		throw_map_error(NULL, -1);
	settings->map = malloc(sizeof(int *) * settings->line_count);
	if (!settings->map)
		throw_map_error(NULL, -1);
	i = 0;
	while (i < settings->line_count)
	{
		nb = read(0, buffer, 9999);
		if (nb <= 0)
			throw_map_error(settings, i);
		settings->map[i] = parse_line_stdin(buffer, settings, i);
		i++;
	}
	return (settings);
}
