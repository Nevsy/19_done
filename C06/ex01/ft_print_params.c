/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:31:21 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 11:58:49 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		ft_putstr(&argv[i][j]);
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}
