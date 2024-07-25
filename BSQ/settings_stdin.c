/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:26:29 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 22:34:40 by nev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"
#include <stdlib.h>

void	are_chars_valid_stdin(t_settings *settings)
{
	if (settings->empty == settings->full
		|| settings->empty == settings->obstacle
		|| settings->full == settings->obstacle)
	{
		ft_putstr("map error\n");
		exit(1);
	}
}
