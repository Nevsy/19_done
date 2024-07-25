/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:11 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/23 09:35:05 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcat(char *dest, char *src, int index)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	dest[index + i] = '\0';
	return (i);
}

void	cat_this_shit(int size, char **strs, char *sep, char *string)
{
	int	i;
	int	current_size;
	int	sep_strlen;

	i = 0;
	current_size = 0;
	sep_strlen = ft_strlen(sep);
	while (i < size)
	{
		current_size += ft_strcat(string, strs[i], current_size);
		if (++i != size - 1)
		{
			ft_strcat(string, sep, current_size);
			current_size += sep_strlen;
		}
	}
}
/*c'est de la merde ta fonction*/

int	calc_size(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		strs_size;

	strs_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			strs_size++;
		i++;
	}
	j = 0;
	while (sep[j] && size != 0)
		j++;
	return (strs_size + j * (size - 1));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		tot_size;

	if (size == 0)
	{
		string = malloc(1);
		*string = '\0';
		return (string);
	}
	tot_size = calc_size(size, strs, sep) + 1;
	string = malloc(sizeof(char) * (tot_size));
	if (!string)
		return (NULL);
	string[0] = '\0';
	string[tot_size - 1] = '\0';
	cat_this_shit(size, strs, sep, string);
	return (string);
}

/*#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	else
	{
		printf("%s\n", ft_strjoin(3, argv, argv[2]));
		printf("empty: %s", ft_strjoin(0, argv, argv[2]));
	}
	return (0);
}*/