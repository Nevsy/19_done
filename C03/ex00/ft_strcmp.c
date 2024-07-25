/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:59:00 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 18:06:00 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int main (void)
{
	char s1[12] = "Helzo world";
	char s2[12] = "Helao world";
	printf("test ft: %d\n", ft_strcmp(s1, s2));
	printf("test strcmp: %d", ft_strcmp(s1, s2));
}*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
