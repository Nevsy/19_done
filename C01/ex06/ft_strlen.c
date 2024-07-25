/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:09:29 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/03 10:09:30 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/*#include <stdio.h>
int	main()
{
	char *test1 = "hello world"; // 11
	char *test2 = "hello"; // 5
	int len1 = ft_strlen(test1);
	int len2 = ft_strlen(test2);
	printf("%d\n", len1);
	printf("%d\n", len2);
 	return (0);
}*/