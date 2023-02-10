/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:26:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 05:29:40 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_game_over()
{
	printf("Game Over! Player touched an enemy patrol.\n");
	exit(EXIT_SUCCESS);
}

static void ft_game_win()
{
	printf("Game Win! All collections have been collected.\n");
	exit(EXIT_SUCCESS);
}

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
		ft_game_over();
	else if (data->map[next_row][next_col] == 'E' && data->map_collectible_count == 0)
		ft_game_win();
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