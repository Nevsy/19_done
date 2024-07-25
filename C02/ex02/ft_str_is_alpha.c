/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:25:47 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 11:41:06 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
			return (0);
		str++;
	}
	return (1);
}

/*#include <stdio.h>
int main(void)
{
	char test0[11] = "Hello world"; // espace -> 0
	int test1 = ft_str_is_alpha(test0);
	char test2[11] = "HelloWorld"; // -> 1
	int test3 = ft_str_is_alpha(test2);
	printf("test 0: %d, test 1: %d", test1, test3);
	return 0;
}*/