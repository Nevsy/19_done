/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:56 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/09 16:42:13 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char str[] = "  ---++--4B";
	printf("%d", ft_atoi_base(str, "0123456789ABCDEF"));
	//printf("%d", ft_atoi_base(str, "01"));
	return (0);
}*/

int	check_validity(char *base)
{
	int	base_len;
	int	j;

	base_len = 0;
	while (base[base_len])
	{
		if (base[base_len] == '+'
			|| base[base_len] == '-')
			return (-1);
		j = 0;
		while (j < base_len)
		{
			if (base[base_len] == base[j++])
				return (-1);
		}
		base_len++;
	}
	if (base_len <= 1)
		return (-1);
	return (base_len);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;

	base_len = check_validity(base);
	if (base_len == -1)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (is_in_base(str[i], base) == -1)
			break ;
		result = result * base_len + is_in_base(str[i++], base);
	}
	return (result * sign);
}
