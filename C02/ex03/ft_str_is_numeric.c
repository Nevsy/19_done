/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:34:26 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 11:04:29 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}
/*#include <stdio.h>

int main(void)
{
	char test0[11] = "1123 "; // espace -> 0
	int test1 = ft_str_is_numeric(test0);
	char test2[11] = "1123"; // -> 1
	int test3 = ft_str_is_numeric(test2);
	printf("test 0: %d, test 1: %d", test1, test3);
	return 0;
}*/