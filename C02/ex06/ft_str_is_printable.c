/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:23:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 10:31:17 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			return (0);
		str++;
	}
	return (1);
}

/*int main(void)
{
	char test0[] = "Hello world"; // -> 1
	int test1 = ft_str_is_printable(test0);
	char test2[11] = "helloworld"; 
	test2[3] = 14; // ... -> 0
	int test3 = ft_str_is_printable(test2);
	printf("test 0: %d, test 1: %d", test1, test3);
	return 0;
}*/
