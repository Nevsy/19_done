/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:16 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 22:58:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_functions.h"

int	get_file(char *filepath)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	return (fd);
}

int	get_file_size(int file_desc)
{
	int		len;
	int		nb;
	char	c[10000];

	len = 0;
	nb = read(file_desc, c, 10000);
	while (nb > 0)
	{
		len += nb;
		nb = read(file_desc, c, 10000);
	}
	return (len);
}

void	get_line(int file_desc)
{
	int		i;
	char	c;

	i = 0;
	while (read(file_desc, &c, 1) > 0 && c != '\n')
		i++;
}

int	column_length_check(t_settings *settings, int count, int line)
{
	if (settings->column_count == -1)
	{
		settings->column_count = count;
		return (1);
	}
	else if (settings->column_count == count)
		return (1);
	else
	{
		free_settings_until(settings, line);
		return (0);
	}
}

char	*get_first_line(int file_desc)
{
	char	c;
	char	buffer[10000];
	int		i;

	i = 0;
	while (read(file_desc, &c, 1) && c != '\n')
	{
		buffer[i] = c;
		i++;
	}
	if (i < 4)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}
