/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:00:04 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/11 09:42:20 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	//char haystack[] = "0123456789";
	char haystack[] = "abcdefghijklmnopqrsdeftuvwxyz";
	//char *needle = NULL;
	//char needle[] = "1";
	char needle[] = "deft";
	
	printf("strstr: %s\n", strstr(haystack, needle));
	fflush(stdout);
	printf("ft: %s\n", ft_strstr(haystack, needle));
	return 0;
}*/

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	index_potential_find;

	i = 0;
	if (!to_find[0] | !to_find | !str)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			index_potential_find = i;
			while (str[i] && to_find[j] && str[i] == to_find[j])
			{
				i++;
				j++;
			}
			if (!to_find[j])
				return (&str[index_potential_find]);
		}
		i++;
	}
	return ((char *)0);
}
