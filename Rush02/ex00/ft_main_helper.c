/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:21:32 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 23:06:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"
#include <stdlib.h>

int	count_pretty_str_len(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i + count] && !((str[i + count] >= 9
				&& str[i + count] <= 13) || str[i + count] == 32))
		count++;
	return (count);
}

char	*prettify_number(char *str)
{
	int		i;
	int		j;
	char	*pretified;

	i = 0;
	j = 0;
	pretified = malloc(sizeof(char) * (count_pretty_str_len(str) + 3));
	if (pretified == 0)
		return (NULL);
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13)
			|| str[i] == 32 || str[i] == '0'))
		i++;
	if (str[i] == '-')
	{
		free(pretified);
		ft_putstr("Error");
		return (NULL);
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		pretified[j++] = str[i++];
	pretified[j] = '\0';
	return (pretified);
}

int	throw_directory_error(void)
{
	ft_putstr("Path invalid.\n");
	return (0);
}

int	throw_dict_error(void)
{
	ft_putstr("Dict Error\n");
	return (0);
}

int	path_is_valid(char *path)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(path);
	while (i < len)
	{
		while ((path[len - 1 - i] >= 9
				&& path[len - 1 - i] <= 13) || path[len - 1 - i] == 32)
			i++;
		path[len - i] = '\0';
		if (path[len - 1 - i] == '.'
			|| path[len - 1 - i] == '\\' || path[len - 1 - i] == '/')
			return (throw_directory_error());
		else if (path[len - 1 - i] == 't')
		{
			if (ft_strcmp(&path[len - 1 - i - 4], ".dict") == 0)
				return (1);
			else
				return (throw_dict_error());
		}
		else
			return (throw_dict_error());
	}
	return (0);
}
