/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/05 11:19:08 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	long	division;
	long	rest;
	long	number;

	number = nb;
	if (number < 0)
	{
		c = '-';
		write(1, &c, 1);
		number *= -1;
	}
	if (number < 10)
	{
		c = number + '0';
		write(1, &c, 1);
	}
	else
	{
		division = number / 10;
		rest = number % 10;
		ft_putnbr(division);
		ft_putnbr(rest);
	}
}

/*int main(void)
{
 	char	c;

 	c = '\n';
 	ft_putnbr(500);
 	write(1, &c, 1);
 	ft_putnbr(00);
 	write(1, &c, 1);
 	ft_putnbr(-4200);
 	return (0);
}*/