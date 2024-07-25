/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:27 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 23:08:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_functions.h"

t_settings	*parse_settings2(int i, t_settings *settings, char *buff)
{
	int	j;

	j = 0;
	settings->line_count = 0;
	while (j < i - 3)
	{
		if (settings->line_count > 214748360)
			return (free_settings(settings));
		settings->line_count = settings->line_count * 10 + buff[j++] - '0';
	}
	settings->column_count = 999;
	free(buff);
	return (settings);
}

t_settings	*parse_settings(int file_desc)
{
	int			i;
	t_settings	*settings;
	char		*buff;

	buff = get_first_line(file_desc);
	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i])
		i++;
	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->full = buff[i - 1];
	settings->obstacle = buff[i - 2];
	settings->empty = buff[i - 3];
	return (parse_settings2(i, settings, buff));
}

int	*parse_line(int file_desc, t_settings *settings, int index)
{
	int		i;
	char	c;
	int		*map_line;

	i = 0;
	map_line = malloc(sizeof(int) * (settings->column_count + 1));
	if (map_line == 0)
		return (free_settings_until(settings, index));
	while (read(file_desc, &c, 1) > 0 && c != '\n')
	{
		if (c == settings->empty)
			map_line[i] = 1;
		else if (c == settings->obstacle)
			map_line[i] = 0;
		else
			return (free_settings_until(settings, index));
		i++;
	}
	if (c != '\n')
		return (free_settings_until(settings, index - 1));
	if (index != 0 && !column_length_check(settings, i, index))
		return (free_settings_until(settings, index - 1));
	else
		settings->column_count = i;
	return (map_line);
}

t_settings	*parse_file2(char *filepath, int file_desc, t_settings *settings)
{
	int		i;
	char	c;

	close(file_desc);
	file_desc = get_file(filepath);
	settings->map = malloc(sizeof(int *) * settings->line_count);
	if (!settings->map)
		return (NULL);
	get_line(file_desc);
	i = 0;
	while (i < settings->line_count)
	{
		settings->map[i] = parse_line(file_desc, settings, i);
		i++;
	}
	if (read(file_desc, &c, 1) != 0)
		return (free_settings(settings));
	return (settings);
}

t_settings	*parse_file(char *filepath)
{
	int			file_desc;
	t_settings	*settings;

	file_desc = get_file(filepath);
	settings = parse_settings(file_desc);
	if (!settings)
		return (NULL);
	if (!are_chars_valid(settings))
		return (NULL);
	if (settings->line_count > 0)
		settings->column_count
			= get_file_size(file_desc) / settings->line_count - 1;
	if (!are_lens_valid(settings))
		return (NULL);
	return (parse_file2(filepath, file_desc, settings));
}
