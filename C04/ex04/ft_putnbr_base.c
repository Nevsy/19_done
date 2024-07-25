/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:41:51 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/09 16:41:54 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	index_potential_find;

	i = 0;
	j = 0;
	index_potential_find = -1;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			index_potential_find = i;
			while (str[i] && to_find[j] && str[i++] == to_find[j++])
				if (to_find[j] == '\0')
					return (str + index_potential_find);
		}
		i++;
	}
	return (NULL);
}

int	check_validity(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
	{
		if (base[base_len] == '+'
			|| base[base_len] == '-'
			|| ft_strstr(base, &base[base_len]) == NULL)
			return (-1);
		base_len++;
	}
	if (base_len <= 1)
		return (-1);
	return (base_len);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	nb2;
	int		base_len;

	base_len = check_validity(base);
	if (base_len == -1)
		return ;
	nb2 = nb;
	if (nb2 < 0)
	{
		nb2 *= -1;
		ft_putchar('-');
	}
	if (nb2 < base_len)
		ft_putchar(base[nb2]);
	else
	{
		ft_putnbr_base(nb2 / base_len, base);
		ft_putchar(base[nb2 % base_len]);
	}
}

/*int	main(void)
{
	ft_putnbr_base(45874, "01");
	return (0);
}*/
