/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:22 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/03 10:09:23 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/*int	main(void)
{
	char *test1 = "hello world";
	char *newLine = "\n";
	char *test2 = "second hello world";

	ft_putstr(test1);
	ft_putstr(newLine);
	ft_putstr(test2);
	return 0;
}*/
