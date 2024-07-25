/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_helper2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:28:03 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 21:08:51 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_helper.h"

// MARK: INIT ARR
void	init_arr(t_number_str_link *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i].number[0] = '\0';
		arr[i].str[0] = '\0';
		i++;
	}
}

// MARK: DICT ERR
void	*put_dict_error(void)
{
	ft_putstr("Dict Error\n");
	return (NULL);
}

// MARK: GET FILE
int	get_file(char *filepath)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.");
		return (-1);
	}
	return (fd);
}

// MARK: SKIP SPACES but no \n
char	*skip_spaces(int file_desc)
{
	char	c;
	char	*character;

	while (read(file_desc, &c, 1) && ((c >= 11 && c <= 13)
			|| c == 32 || c == 9))
		continue ;
	character = malloc(sizeof(char));
	character[0] = c;
	return (character);
}

// MARK: FREE
void	free_chars(char *character1, char *character2)
{
	free(character1);
	free(character2);
}
