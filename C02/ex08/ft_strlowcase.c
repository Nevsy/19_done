/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:47:48 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 11:42:40 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] < 'A' || str[i] > 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int main(void)
{
	char test0[12] = "HeLLo WORlD";
	char test2[12] = "HELLO WORLD";
	char *test1 = ft_strlowcase(test0);
	char *test3 = ft_strlowcase(test2);

	printf("test 0: %s, test 2: %s\n", test0, test2);
	printf("test 1: %s, test 3: %s", test1, test3);
	return 0;
}*/
