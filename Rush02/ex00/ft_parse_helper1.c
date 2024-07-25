/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_helper1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:19:30 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 21:06:11 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_helper.h"

// MARK: COUNT LINES
int	count_non_empty_lines(int file_desc)
{
	char	c;
	char	prev;
	int		count;

	prev = '\n';
	count = 0;
	while (read(file_desc, &c, 1))
	{
		if (c == '\n' && prev != '\n')
			count++;
		prev = c;
	}
	return (count);
}

// MARK: GET COLON
char	*get_colon(int file_desc, char c)
{
	char	*character;

	if (!((c >= 11 && c <= 13) || c == 32 || c == 9 || c == ':'))
		return (put_dict_error());
	if (c != ':')
		c = *skip_spaces(file_desc);
	if (c != ':')
		return (put_dict_error());
	character = malloc(sizeof(char *));
	character[0] = c;
	return (character);
}
