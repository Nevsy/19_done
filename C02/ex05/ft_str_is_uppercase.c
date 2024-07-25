/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:25:47 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 10:31:26 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'A' || *str > 'Z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*#include <stdio.h>
int main(void)
{
	char test0[11] = "hELLOWORLD"; // h -> 0
	int test1 = ft_str_is_uppercase(test0);
	char test2[11] = "HELLOWORLD"; // 1
	int test3 = ft_str_is_uppercase(test2);
	printf("test 0: %d, test 1: %d", test1, test3);
	return 0;
}*/
