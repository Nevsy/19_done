/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:35:07 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 10:21:47 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'a' || *str > 'z'))
			return (0);
		str++;
	}
	return (1);
}

/*#include <stdio.h>

int main(void)
{
	char test0[11] = "Helloworld"; // H -> 0
	int test1 = ft_str_is_lowercase(test0);
	char test2[11] = "helloworld"; // -> 1
	int test3 = ft_str_is_lowercase(test2);
	printf("test 0: %d, test 1: %d", test1, test3);
	return 0;
}*/