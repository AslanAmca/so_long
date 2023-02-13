/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:26:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 05:37:53 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_game_over(t_data *data)
{
	ft_close_handler(data, "Game Over! Player touched an enemy patrol.\n");
}

static void	ft_game_win(t_data *data)
{
	ft_close_handler(data, "Game Win! All collections have been collected.\n");
}

static char	*ft_get_asset_name(int keycode)
{
	if (keycode == keycode_w)
		return (PLAYER_UP_1);
	else if (keycode == keycode_s)
		return (PLAYER_DOWN_1);
	else if (keycode == keycode_a)
		return (PLAYER_LEFT_1);
	else if (keycode == keycode_d)
		return (PLAYER_RIGHT_1);
	else
		return (NULL);
}

static void	ft_print_move_count(t_data *data)
{
	char	*move_count;
	int		color;

	move_count = ft_itoa(data->player_move_count);
	color = 0xffffff;
	ft_put_image(data, PLAYER_MOVE_COUNT, 0, 0);
	if (data->player_move_count < 10)
		mlx_string_put(data->mlx, data->mlx_window, 23, 50, color, move_count);
	else if (data->player_move_count < 100)
		mlx_string_put(data->mlx, data->mlx_window, 20, 50, color, move_count);
	else
		mlx_string_put(data->mlx, data->mlx_window, 18, 50, color, move_count);
	free(move_count);
	move_count = NULL;
}

void	ft_player_move(t_data *data, int next_row, int next_col, int keycode)
{
	char	*asset_name;

	asset_name = ft_get_asset_name(keycode);
	if (data->map[next_row][next_col] == '1' ||
	(data->map[next_row][next_col] == 'E' && data->map_collectible_count > 0))
		return ;
	else if (data->map[next_row][next_col] == 'X')
		ft_game_over(data);
	else if (data->map[next_row][next_col] == 'E' &&
	data->map_collectible_count == 0)
		ft_game_win(data);
	else if (data->map[next_row][next_col] == 'C')
		data->map_collectible_count--;
	data->map[data->player_row][data->player_col] = '0';
	data->map[next_row][next_col] = 'P';
	ft_put_image(data, GROUND, data->player_row, data->player_col);
	ft_put_image(data, asset_name, next_row, next_col);
	data->player_row = next_row;
	data->player_col = next_col;
	data->player_direction = keycode;
	data->player_move_count++;
	ft_print_move_count(data);
}
