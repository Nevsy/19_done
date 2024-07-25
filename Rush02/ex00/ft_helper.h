/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:17:25 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 22:31:46 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
# define FT_HELPER_H

// MARK: LINK
typedef struct number_str_link
{
	char	number[1024];
	char	str[2048];
	int		len_number;
}	t_number_str_link;

// PARSE.C
t_number_str_link	*parse_file(int file_desc, char *filepath);

// HELPER (general stuff)
int					ft_atoi(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);

// PARSE 1
int					count_non_empty_lines(int file_desc);
char				*get_colon(int file_desc, char c);

// PARSE 2
int					get_file(char *filepath);
char				*skip_spaces(int file_desc);
void				*put_dict_error(void);
void				init_arr(t_number_str_link *arr, int size);
void				free_chars(char *character1, char *character2);

// Print numbers
void				print_digit(t_number_str_link *dict, char c);
void				print_elem(t_number_str_link *dict, char *c);
int					find_power(char *str, t_number_str_link *dict);
void				print_number(char *str, t_number_str_link *dict);
void				print_zero(t_number_str_link *dict, char *prettify_number);

// MAIN
void				free_dict_numbers(t_number_str_link *dict,
						char *prettify_number);
char				*prettify_number(char *str);
int					count_pretty_str_len(char *str);
int					path_is_valid(char *path);

#endif
