/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:46:28 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:01:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_walls(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map_row_count)
	{
		if (data->map[row][0] != '1' ||
			data->map[row][data->map_col_count - 1] != '1')
			ft_print_error("The map must be closed/surrounded by walls. (1)");
		row++;
	}
	col = 0;
	while (col < data->map_col_count)
	{
		if (data->map[0][col] != '1' ||
			data->map[data->map_row_count - 1][col] != '1')
			ft_print_error("The map must be closed/surrounded by walls. (1)");
		col++;
	}
}
