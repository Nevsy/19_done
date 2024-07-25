/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:16:40 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/18 16:54:05 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	partition(char **array, int low, int high, int (*cmp)(char *, char *))
{
	char	*pivot;
	char	*temp;
	int		i;
	int		j;

	pivot = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (cmp(array[j], pivot) < 0)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
		j++;
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	return (i);
}

void	quicksort(char **array, int low, int high, int (*cmp)(char *, char *))
{
	int	pivot_index;

	if (low >= high || low < 0)
		return ;
	pivot_index = partition(array, low, high, cmp);
	quicksort(array, low, pivot_index - 1, cmp);
	quicksort(array, pivot_index + 1, high, cmp);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	quicksort(tab, 0, i, cmp);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;

	argv[argc - 1] = NULL;
	ft_sort_string_tab(argv, &ft_strcmp);
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
