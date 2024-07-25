/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:43:52 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 21:15:34 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_helper.h"

// MARK: GET NUMBER
char	*get_rest_of_number(int file_desc,
	t_number_str_link *numbers,
	int current_line)
{
	int		current_col;
	char	c;
	char	*character;

	current_col = 1;
	while (read(file_desc, &c, 1) && (c >= '0' && c <= '9'))
		numbers[current_line].number[current_col++] = c;
	numbers[current_line].number[current_col] = '\0';
	numbers[current_line].len_number = ft_strlen(numbers[current_line].number);
	character = malloc(sizeof(char));
	character[0] = c;
	return (character);
}

// MARK: GET STR
char	*get_rest_of_str(int file_desc,
	t_number_str_link *numbers,
	int current_line)
{
	char	*character;
	char	c;
	int		current_col;

	current_col = 1;
	while (read(file_desc, &c, 1)
		&& (c != '\n')
		&& (c >= 32 && c <= 126))
		numbers[current_line].str[current_col++] = c;
	numbers[current_line].str[current_col] = '\0';
	character = malloc(sizeof(char));
	character[0] = c;
	return (character);
}

// MARK: PARSE STRUCTS
t_number_str_link	*parse_structs(
	t_number_str_link *numbers,
	int file_desc,
	int non_empty_lines,
	int current_line)
{
	char	c;
	char	*character1;
	char	*character2;

	while (current_line < non_empty_lines)
	{
		if (read(file_desc, &c, 1) && c == '\n')
			continue ;
		else if (c >= '0' && c <= '9')
			numbers[current_line].number[0] = c;
		character1 = get_rest_of_number(file_desc, numbers, current_line);
		character2 = get_colon(file_desc, *character1);
		if (character2 == NULL)
			return (NULL);
		free_chars(character1, character2);
		character1 = skip_spaces(file_desc);
		if (!((*character1 >= 31 && *character1 <= 126)) || *character1 == 10)
			return (put_dict_error());
		numbers[current_line].str[0] = *character1;
		character2 = get_rest_of_str(file_desc, numbers, current_line++);
		if (*character2 != '\n' || !*character2)
			return (put_dict_error());
		free_chars(character1, character2);
	}
	return (numbers);
}

// MARK: PARSE
t_number_str_link	*parse_file(int file_desc, char *filepath)
{
	t_number_str_link	*numbers;
	int					non_empty_lines;
	int					current_line;

	non_empty_lines = count_non_empty_lines(file_desc);
	numbers = malloc(sizeof(t_number_str_link) * (non_empty_lines + 1));
	init_arr(numbers, non_empty_lines);
	close(file_desc);
	file_desc = get_file(filepath);
	current_line = 0;
	if (parse_structs(numbers, file_desc,
			non_empty_lines, current_line) == NULL)
		return (NULL);
	numbers[non_empty_lines].str[0] = '\0';
	close(file_desc);
	return (numbers);
}
