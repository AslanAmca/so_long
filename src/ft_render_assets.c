/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:19:18 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 04:25:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// img'ı data içerisinde tutmak gerekebilir. Böyle bir durumda free yerine mlx fonksiyonu kullanılmalı.
// width ve height data içerisinde tutmak gerekebilir.
void ft_put_image_to_window(t_data *data, char *img_name, int row, int col)
{
	int width;
	int height;
	void *img;

	img = mlx_xpm_file_to_image(data->mlx, img_name, &width, &height);
	if (img == NULL)
		ft_print_error("Image not found.");
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, col * ASSET_SIZE, row * ASSET_SIZE);
	free(img);
	img = NULL;
}

static void ft_render_map(t_data *data, int row, int col)
{
	if (row == 0 && col == 0)
		ft_put_image_to_window(data, PLAYER_MOVE_COUNT, row, col);
	else if (data->map[row][col] == '0')
		ft_put_image_to_window(data, GROUND, row, col);
	else if (data->map[row][col] == '1')
		ft_put_image_to_window(data, WALL, row, col);
	else if (data->map[row][col] == 'C')
		ft_put_image_to_window(data, COLLECTIBLE, row, col);
	else if (data->map[row][col] == 'X')
		ft_put_image_to_window(data, ENEMY_LEFT_1, row, col);
	else if (data->map[row][col] == 'P')
	{
		data->player_row = row;
		data->player_col = col;
		ft_put_image_to_window(data, PLAYER_RIGHT_1, row, col);
	}
	else if (data->map[row][col] == 'E')
	{
		data->exit_row = row;
		data->exit_col = col;
		ft_put_image_to_window(data, EXIT_1, row, col);
	}
}

void ft_render_assets(t_data *data)
{
	int row;
	int col;

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



// PLAYER HAREKETLERİ

static void ft_print_move_count(t_data *data)
{
	char *move_count;
	move_count = ft_itoa(data->player_move_count);
	ft_put_image_to_window(data, PLAYER_MOVE_COUNT, 0, 0);
	if (data->player_move_count < 10)
		mlx_string_put(data->mlx, data->mlx_window, 23, 50, 0xffffff, move_count);
	else if (data->player_move_count < 100)
		mlx_string_put(data->mlx, data->mlx_window, 20, 50, 0xffffff, move_count);
	else
		mlx_string_put(data->mlx, data->mlx_window, 18, 50, 0xffffff, move_count);

	// Memory Allocation Güvenliği için kalabilir.
	free(move_count);
	move_count = NULL;
}

void ft_player_move(t_data *data, int next_row, int next_col, int keycode, char *asset_name)
{
	int current_row;
	int current_col;

	current_row = data->player_row;
	current_col = data->player_col;
	if (data->map[next_row][next_col] == '1' || (data->map[next_row][next_col] == 'E' && data->map_collectible_count > 0))
		return;
	else if (data->map[next_row][next_col] == 'X')
		exit(EXIT_SUCCESS);
	else if (data->map[next_row][next_col] == 'E' && data->map_collectible_count == 0)
		exit(EXIT_SUCCESS);
	else if (data->map[next_row][next_col] == 'C')
		data->map_collectible_count--;
	data->player_row = next_row;
	data->player_col = next_col;
	data->player_move_count++;
	data->player_direction = keycode;
	data->map[current_row][current_col] = '0';
	data->map[next_row][next_col] = 'P';
	ft_put_image_to_window(data, GROUND, current_row, current_col);
	ft_put_image_to_window(data, asset_name, next_row, next_col);
	ft_print_move_count(data);
}
