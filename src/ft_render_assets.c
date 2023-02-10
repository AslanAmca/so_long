/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:19:18 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 05:58:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_put_image(t_data *data, char *img_name, int row, int col)
{
	int		width;
	int		height;
	void	*img;

	row = row * ASSET_SIZE;
	col = col * ASSET_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, img_name, &width, &height);
	if (img == NULL)
		ft_print_error("Image not found.");
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, col, row);
	free(img);
	img = NULL;
}

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
