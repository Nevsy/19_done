/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:45 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/23 09:27:57 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	s_stock_str			*tab;
	char				*str;

	i = 0;
	tab = malloc(sizeof(s_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	while (i < ac)
	{
		str = av[i];
		tab[i].size = ft_strlen(str);
		tab[i].str = str;
		ft_strcpy(tab[i].copy, str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
