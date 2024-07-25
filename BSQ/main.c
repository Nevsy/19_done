/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:25:47 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 22:53:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	path_is_valid(char *path)
{
	int	file_desc;

	file_desc = open(path, O_WRONLY);
	if (file_desc == -1)
	{
		return (0);
	}
	close(file_desc);
	return (1);
}

void	do_the_thing_stdin(void)
{
	t_settings	*settings;
	int			i;

	settings = parse_stdin();
	if (!settings)
		return ;
	settings->big = malloc(sizeof(t_point));
	if (!settings->big)
		return ;
	modify_square(settings->map, settings);
	draw_square(settings->map, settings, settings->big);
	i = 0;
	free(settings->big);
	while (i < settings->line_count)
	{
		free(settings->map[i]);
		i++;
	}
	free(settings->map);
	free(settings);
}

void	do_the_thing_normal(char *avi)
{
	t_settings	*settings;

	settings = parse_file(avi);
	if (!settings)
		return ;
	settings->big = malloc(sizeof(t_point));
	if (!settings->big)
		return ;
	modify_square(settings->map, settings);
	draw_square(settings->map, settings, settings->big);
	free(settings->big);
	free_settings_main(settings);
}

int	main(int ac, char **av)
{
	int			i;

	if (ac == 1)
	{
		do_the_thing_stdin();
	}
	i = 1;
	while (i < ac)
	{
		if (!path_is_valid(av[i]))
			ft_putstr("map error\n");
		else
			do_the_thing_normal(av[i]);
		i++;
	}
}
