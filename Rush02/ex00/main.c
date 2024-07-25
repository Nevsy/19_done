/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:33:11 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 22:57:57 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_helper.h"

int	print_main_error(int argc)
{
	if (argc < 2)
	{
		ft_putstr("Number is missing.");
		return (1);
	}
	else if (argc > 3)
	{
		ft_putstr("Too many arguments.");
		return (1);
	}
	return (1);
}

void	free_dict_numbers(t_number_str_link *dict, char *prettify_number)
{
	if (dict != NULL)
		free(dict);
	if (prettify_number != NULL)
		free(prettify_number);
}

void	call_two_args(char **argv)
{
	int					file_desc;
	t_number_str_link	*dict;
	char				*pretty_num;

	pretty_num = prettify_number(argv[1]);
	file_desc = get_file("numbers.dict");
	if (file_desc == -1)
		return ;
	dict = parse_file(file_desc, "numbers.dict");
	if (dict != NULL && pretty_num != NULL && pretty_num[0] != '\0')
		print_number(pretty_num, dict);
	else if (pretty_num != NULL && pretty_num[0] == '\0')
	{
		print_zero(dict, pretty_num);
		return ;
	}
	free_dict_numbers(dict, pretty_num);
}

void	call_three_args(char **argv)
{
	int					file_desc;
	t_number_str_link	*dict;
	char				*pretty_num;

	if (!path_is_valid(argv[1]))
	{
		ft_putstr("Invalid path.");
		return ;
	}
	pretty_num = prettify_number(argv[2]);
	file_desc = get_file(argv[1]);
	if (file_desc == -1)
		return ;
	dict = parse_file(file_desc, argv[1]);
	if (dict != NULL && pretty_num != NULL && pretty_num[0] != '\0')
		print_number(pretty_num, dict);
	else if (pretty_num != NULL && pretty_num[0] == '\0')
	{
		print_zero(dict, pretty_num);
		return ;
	}
	free_dict_numbers(dict, pretty_num);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (print_main_error(argc));
	else if (argc > 3)
		return (print_main_error(argc));
	if (argc == 2)
		call_two_args(argv);
	else
		call_three_args(argv);
	return (0);
}
