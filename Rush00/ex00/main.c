/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:25:18 by jdebrull          #+#    #+#             */
/*   Updated: 2024/07/06 15:41:33 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y, char *str);

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 214748364)
			return (0);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	if (ac == 4 && ft_len(av[3]) == 7)
		rush(ft_atoi(av[1]), ft_atoi(av[2]), av[3]);
	else if (ac == 3)
		rush(ft_atoi(av[1]), ft_atoi(av[2]), "oooo-| ");
	else if (ac == 2 && ft_len(av[1]) == 7)
		rush(100, 10, av[1]);
	else if (ac == 1)
		rush(100, 10, "oooo-| ");
	else
		rush(0, 0, "oooo-| ");
	return (0);
}
