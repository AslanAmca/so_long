/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:46:28 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/07 19:08:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_col_count)
	{
		if (data->map[0][i] != '1' ||
			data->map[data->map_row_count - 1][i] != '1')
			ft_print_error("The map must be closed/surrounded by walls. (1)");
		i++;
	}
	j = 0;
	while (j < data->map_row_count)
	{
		if (data->map[j][0] != '1' ||
			data->map[j][data->map_col_count - 1] != '1')
			ft_print_error("The map must be closed/surrounded by walls. (1)");
		j++;
	}
}
