/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:04:16 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 17:25:39 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	addition(int x, int y)
{
	return (x + y);
}

int	subtraction(int x, int y)
{
	return (x - y);
}

int	multiplication(int x, int y)
{
	int	res;

	res = x * y;
	return (res);
}

int	modulo(int x, int y)
{
	return (x % y);
}

int	division(int x, int y)
{
	return (x / y);
}

int	do_operation(int a, int b, int (*operation)(int, int))
{
	return (operation(a, b));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	int	result;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (!ft_strcmp(argv[2], "\%"))
	{
		if (b == 0)
		{
			write(1, "Stop : modulo by zero", 21);
			return (0);
		}
		result = do_operation(a, b, modulo);
	}
	else if (!ft_strcmp(argv[2], "/"))
	{
		if (b == 0)
		{
			write(1, "Stop : division by zero", 23);
			return (0);
		}
		result = do_operation(a, b, division);
	}
	else if (!ft_strcmp(argv[2], "*"))
		result = do_operation(a, b, multiplication);
	else if (!ft_strcmp(argv[2], "+"))
		result = do_operation(a, b, addition);
	else if (!ft_strcmp(argv[2], "-"))
		result = do_operation(a, b, subtraction);
	else
		result = 0;
	ft_putnbr(result);
	return (0);
}
