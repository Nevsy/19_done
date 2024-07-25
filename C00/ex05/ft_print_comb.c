/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/05 11:08:07 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_digit(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

void	write_comma(int n, int m, int o)
{
	char	c;

	if (n == 7 && m == 8 && o == 9)
	{
		return ;
	}
	c = ',';
	write(1, &c, 1);
	c = ' ';
	write(1, &c, 1);
}

void	write_stage(int i, int j, int k)
{
	write_digit(i);
	write_digit(j);
	write_digit(k);
	write_comma(i, j, k);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				write_stage(i, j, k);
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
