/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:16:40 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/17 09:50:55 by sroyer           ###   ########.fr       */
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

int	partition(char **array, int low, int high)
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
		if (ft_strcmp(array[j], pivot) < 0)
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

void	quicksort(char **array, int low, int high)
{
	int	pivot_index;

	if (low >= high || low < 0)
		return ;
	pivot_index = partition(array, low, high);
	quicksort(array, low, pivot_index - 1);
	quicksort(array, pivot_index + 1, high);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	quicksort(tab, 0, i);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;

	argv[argc - 1] = NULL;
	ft_sort_string_tab(argv);
	i = 0;
	while (i < argc - 1)
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
