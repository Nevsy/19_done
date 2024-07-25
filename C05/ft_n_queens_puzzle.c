/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:n:57 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/16 11:11:39 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

int	is_solution_valid(int n, int solution[n], int index_added)
{
	int	i;
	int	diag_pos_index;
	int	diag_neg_index;

	i = 0;
	diag_pos_index = index_added + solution[index_added];
	diag_neg_index = index_added - solution[index_added];
	while (i < index_added)
	{
		if (solution[i] == solution[index_added]
			|| i - solution[i] == diag_neg_index
			|| i + solution[i] == diag_pos_index)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_solution(int n, int solution[n])
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(solution[i]);
		if (solution[i] > 9)
			write(1, " ", 1);
		if (i == n - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	backtrack(int n, int solution[n], int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (index == n)
	{
		print_solution(n, solution);
		return (1);
	}
	while (i < n)
	{
		solution[index] = i;
		if (is_solution_valid(n, solution, index))
			count += backtrack(n, solution, index + 1);
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(int n)
{
	int	solution[n];
	int	count;

	count = backtrack(n, solution, 0);
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_ten_queens_puzzle(8);
	write(1, "\namount of sols: ", 17);
	ft_putnbr(count);
	return (0);
}
