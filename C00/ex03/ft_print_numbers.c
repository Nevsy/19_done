/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/02 11:51:14 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;
	int		i;

	i = 48;
	while (i < 58)
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
}

/*int	main(void){
    ft_print_numbers();
    return 0;
}*/