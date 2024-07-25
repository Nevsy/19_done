/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:03 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/17 15:47:02 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	index_in_base(char c, char *base);

int	check_validity(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
	{
		if (base[base_len] == '+'
			|| base[base_len] == '-'
			|| index_in_base(base[base_len], &base[base_len] + 1) != -1)
			return (-1);
		base_len++;
	}
	if (base_len <= 1)
		return (-1);
	return (base_len);
}

int	ft_atoi_base(char *str, char *base, int base_len)
{
	int		i;
	int		sign;
	int		result;
	int		index;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		index = index_in_base(str[i++], base);
		if (index == -1)
			break ;
		result = result * base_len + index;
	}
	return (result * sign);
}

char	*ft_itoa(int nb, char *base, int base_len, int result_len)
{
	long	nb2;
	int		i;
	char	*result;
	int		sign;

	nb2 = nb;
	result = malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	sign = 0;
	if (nb2 < 0)
	{
		nb2 *= -1;
		result[0] = '-';
		sign = -1;
	}
	while (i < result_len + sign)
	{
		result[result_len - i - 1] = base[nb2 % base_len];
		i++;
		nb2 /= base_len;
	}
	result[result_len] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_len_from;
	int		base_len_to;
	char	*result;
	int		result_len;
	int		atoi;

	base_len_to = check_validity(base_to);
	base_len_from = check_validity(base_from);
	if (base_len_from == -1 || base_len_to == -1)
		return (NULL);
	result_len = 0;
	atoi = ft_atoi_base(nbr, base_from, base_len_from);
	if (atoi <= 0)
	{
		atoi *= -1;
		result_len++;
	}
	while (atoi > 0 && result_len++ < 2147483647)
		atoi /= base_len_to;
	atoi = ft_atoi_base(nbr, base_from, base_len_from);
	result = ft_itoa(atoi, base_to, base_len_to, result_len);
	result[result_len] = '\0';
	return (result);
}

/*int main(int ac, char **av)
{
	(void)ac;
	char *new = ft_convert_base(av[1], av[2], av[3]);
	printf("%s\n", new);
	return (0);
}*/