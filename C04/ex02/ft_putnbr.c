/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:40 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/09 16:41:42 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		nb2 *= -1;
		ft_putchar('-');
	}
	if (nb2 < 10)
		ft_putchar(nb2 + '0');
	else
	{
		ft_putnbr(nb2 / 10);
		ft_putchar(nb2 % 10 + '0');
	}
}

/*int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}*/
