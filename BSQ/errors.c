/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:15:26 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 16:27:50 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_functions.h"
#include <stdlib.h>

/*int	throw_map_err(int error_code, t_settings *settings)
{
	if (error_code == 0)
	{
		free(settings);
		ft_putstr("map error\n");
		return (0);
	}
	return (0);
}*/

void	*throw_parse_err(void)
{
	ft_putstr("map error\n");
	return (NULL);
}
