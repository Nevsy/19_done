/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:08:26 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/10 11:46:58 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] < 'A' || str[i] > 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strlowcase(str);
	i = 0;
	while (str[i])
	{
		if (!(str[i] < 'a' || str[i] > 'z'))
		{
			if (i == 0)
			{
				str[i] -= 32;
			}
			else if ((str[i - 1] < 'a' || str[i - 1] > 'z')
				&& (str[i - 1] < '0' || str[i - 1] > '9')
				&& (str[i - 1] < 'A' || str[i - 1] > 'Z'))
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char test0[62] = "Salut, c4mment tu vas ?
	42mots quarante-deux; cinquante+et+un";
	char *test1 = ft_strcapitalize(test0);
	char correction[62] = "Salut, C4mment Tu Vas ?
	42mots Quarante-Deux; Cinquante+Et+Un";
	int correct = strncmp(test1, correction, 62);

	printf("test 0:\t\t%s\n", test1);
	printf("correction:\t%s\n", correction);
	printf("correct:\t%d", correct); // 0 -> equal
	return 0;
}*/