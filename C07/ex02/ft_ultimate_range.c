/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:15 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/17 15:25:24 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	ptr = malloc(sizeof(int) * (max - min));
	if (!ptr)
		return (-1);
	*range = ptr;
	i = 0;
	while (i < max - min)
	{
		ptr[i] = min + i;
		i++;
	}
	return (max - min);
}

/*#include <stdio.h>
int main(void)
{
	int *range;
	int size = ft_ultimate_range(&range, -5, 10);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");
	printf("size: %d", size);
	free(range);
	return (0);
}*/