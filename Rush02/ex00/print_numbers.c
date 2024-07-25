/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:47:30 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 22:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_helper.h"

void	print_hundred2(char *str, t_number_str_link *dict)
{
	char	tmp;

	if (str[1] == '1')
		print_elem(dict, &str[1]);
	else if (str[1] != '0')
	{
		tmp = str[2];
		str[2] = '0';
		print_elem(dict, &str[1]);
		if (tmp != '0')
		{
			ft_putchar('-');
			print_digit(dict, tmp);
		}
	}
	else if (str[2] != '0')
	{
		if (str[1] == '0' && str[0] != '0')
			ft_putstr("and ");
		print_digit(dict, str[2]);
	}
}

void	print_hundred(char *str, t_number_str_link *dict)
{
	if (str[0] != '0')
	{
		print_digit(dict, str[0]);
		ft_putchar(' ');
		print_elem(dict, "100");
		if (!(str[1] == '0' && str[2] == '0'))
			ft_putchar(' ');
	}
	print_hundred2(str, dict);
}

void	make_next_hundred(char	*str, t_number_str_link *dict)
{
	char	hundred[4];
	int		mod;
	int		i;
	int		j;

	mod = ft_strlen(str) % 3;
	i = 0;
	while (i < 3 - mod && mod != 0)
		hundred[i++] = '0';
	j = 0;
	while (i < 3)
		hundred[i++] = str[j++];
	hundred[i] = '\0';
	print_hundred(hundred, dict);
	if (ft_strlen(str) > 3)
		ft_putchar(' ');
}

void	print_number(char *str, t_number_str_link *dict)
{
	int	power;
	int	mod;
	int	i;

	mod = ft_strlen(str) % 3;
	power = ft_strlen(str) / 3;
	if (mod != 0)
	{
		make_next_hundred(str, dict);
		find_power(str, dict);
	}
	i = 0;
	while (str[i * 3 + mod] && i < power)
	{
		if (!(str[i * 3 + mod] == '0' && str[i * 3 + mod + 1] == '0'
				&& str[i * 3 + mod + 2] == '0'))
		{
			make_next_hundred(&str[i * 3 + mod], dict);
			find_power(&str[i * 3 + mod], dict);
		}
		i++;
	}
}
