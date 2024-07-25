/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:37:57 by brcoppie          #+#    #+#             */
/*   Updated: 2024/07/21 23:05:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"
#include <stdlib.h>

void	print_digit(t_number_str_link *dict, char c)
{
	int	i;

	i = 0;
	while (dict[i].str[0])
	{
		if (ft_strlen(dict[i].number) == 1 && dict[i].number[0] == c)
		{
			ft_putstr(dict[i].str);
			return ;
		}
		i++;
	}
	ft_putstr("Dict Error\n");
}

void	print_elem(t_number_str_link *dict, char *c)
{
	int	i;

	i = 0;
	while (dict[i].str[0])
	{
		if (ft_strcmp(dict[i].number, c) == 0)
		{
			ft_putstr(dict[i].str);
			return ;
		}
		i++;
	}
	ft_putstr("Dict Error\n");
}

void	find_power2(int len, char *power, t_number_str_link *dict)
{
	if (len > 3)
	{
		print_elem(dict, power);
		ft_putchar(' ');
	}
	free(power);
}

int	find_power(char *str, t_number_str_link *dict)
{
	int		i;
	int		len;
	int		mod;
	char	*power;

	len = ft_strlen(str);
	mod = len % 3;
	if (mod == 0)
		mod = 3;
	power = malloc(sizeof(char) * (len + 3));
	if (!power)
		return (0);
	power[0] = '1';
	i = 1;
	while (i <= len - mod)
	{
		power[i] = '0';
		i++;
	}
	power[i] = '\0';
	find_power2(len, power, dict);
	return (0);
}

void	print_zero(t_number_str_link *dict, char *prettify_number)
{
	print_digit(dict, '0');
	free_dict_numbers(dict, prettify_number);
}
