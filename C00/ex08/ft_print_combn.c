/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:57:37 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/05 11:21:30 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	int		division;
	int		rest;

	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		division = nb / 10;
		rest = nb % 10;
		ft_putnbr(division);
		ft_putnbr(rest);
	}
}

void	write_comma(int n, int m)
{
	char	c;

	if (n >= 98 && m >= 99)
	{
		return ;
	}
	c = ',';
	write(1, &c, 1);
	c = ' ';
	write(1, &c, 1);
}

void	write_2_numbers(int n, int m)
{
	char	c;

	write_number(n);
	c = ' ';
	write(1, &c, 1);
	write_number(m);
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < n)
	{
		while (i < 99)
		{
			j = i + 1;
			while (j < 100)
			{
				ft_putnbr(i);
				ft_putnbr(j);
				write_comma(i, j);
				j++;
			}
			j = 0;
			i++;
		}
		k++;
	}
}

// int	main(void)
// {
// 	ft_print_combn(4);
// 	return (0);
// }
