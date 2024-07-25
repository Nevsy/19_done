/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:16:40 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/09 13:29:52 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	partition(int *array, int low, int high)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	pivot = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
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

void	quicksort(int *array, int low, int high)
{
	int	pivot_index;

	if (low >= high || low < 0)
		return ;
	pivot_index = partition(array, low, high);
	quicksort(array, low, pivot_index - 1);
	quicksort(array, pivot_index + 1, high);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quicksort(tab, 0, size - 1);
}

/*#include <stdio.h>
int	main(void)
{
	int	array[] = {5, 8, -4, 21, 1, -9, 2};
	int len = 7;
	ft_sort_int_tab(array, len);
	int i = 0;
	while (i < len)
	{
		printf("%d", array[i]);
		if (i < len - 1)
            printf(", ");
		i++;
	}
	return (0);
}*/
