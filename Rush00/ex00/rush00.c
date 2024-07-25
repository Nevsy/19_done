/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:25:55 by jdebrull          #+#    #+#             */
/*   Updated: 2024/07/06 15:36:19 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	write_line(char begin, char middle, char end, int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
			ft_putchar(begin);
		else if (j == x - 1)
			ft_putchar(end);
		else
			ft_putchar(middle);
		j++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y, char *characters)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
	{
		ft_putchar('\n');
		return ;
	}
	while (i < y)
	{
		if (i == 0)
			write_line(characters[0], characters[4], characters[1], x);
		else if (i == y - 1)
			write_line(characters[2], characters[4], characters[3], x);
		else
			write_line(characters[5], characters[6], characters[5], x);
		i++;
	}
}
