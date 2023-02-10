/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:19:18 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 07:38:33 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	ft_render_map(t_data *data, int row, int col)
{
	if (row == 0 && col == 0)
		ft_put_image(data, PLAYER_MOVE_COUNT, row, col);
	else if (data->map[row][col] == '0')
		ft_put_image(data, GROUND, row, col);
	else if (data->map[row][col] == '1')
		ft_put_image(data, WALL, row, col);
	else if (data->map[row][col] == 'C')
		ft_put_image(data, COLLECTIBLE, row, col);
	else if (data->map[row][col] == 'X')
		ft_put_image(data, ENEMY_LEFT_1, row, col);
	else if (data->map[row][col] == 'P')
	{
		data->player_row = row;
		data->player_col = col;
		ft_put_image(data, PLAYER_RIGHT_1, row, col);
	}
	else if (data->map[row][col] == 'E')
	{
		data->exit_row = row;
		data->exit_col = col;
		ft_put_image(data, EXIT_1, row, col);
	}
}

void	ft_render_assets(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map[row] != NULL)
	{
		col = 0;
		while (data->map[row][col] != '\0')
		{
			ft_render_map(data, row, col);
			col++;
		}
		row++;
	}
}
