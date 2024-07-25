/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:31:27 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/12 10:10:24 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	c;
	int		i;

	i = 0;
	(void)argc;
	while (argv[0][i] != '\0')
	{
		c = argv[0][i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
