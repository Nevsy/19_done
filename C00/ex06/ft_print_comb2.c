/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/05 11:15:20 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// ascii values: 48 -> 58
void	write_digit(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

void	write_number(int n)
{
	char	c;

	if (n < 10)
	{
		c = 0 + 48;
		write(1, &c, 1);
		c = n + 48;
		write(1, &c, 1);
		return ;
	}
	c = n / 10 + 48;
	write(1, &c, 1);
	c = n % 10 + 48;
	write(1, &c, 1);
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

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			write_2_numbers(i, j);
			write_comma(i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
