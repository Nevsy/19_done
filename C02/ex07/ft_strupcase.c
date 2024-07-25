/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:21:31 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 10:33:27 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] < 'a' || str[i] > 'z'))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>

int main(void)
{
	char test0[12] = "HelLo world";
	char test2[12] = "hello world";
	char *test1 = ft_strupcase(test0);
	char *test3 = ft_strupcase(test2);

	printf("test 0: %s, test 2: %s\n", test0, test2);
	printf("test 1: %s, test 3: %s", test1, test3);
	return (0);
}*/
