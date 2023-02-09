/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:42 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 07:06:18 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(EXIT_SUCCESS);
	return (1);
}

int key_press_handler(int keycode, t_data *data)
{
	if (keycode == keycode_esc)
		close_handler(data);
	if (keycode == keycode_w)
		ft_player_move(data, data->player_row - 1, data->player_col, keycode, PLAYER_UP_1);
	if (keycode == keycode_s)
		ft_player_move(data, data->player_row + 1, data->player_col, keycode, PLAYER_DOWN_1);
	if (keycode == keycode_a)
		ft_player_move(data, data->player_row, data->player_col - 1, keycode, PLAYER_LEFT_1);
	if (keycode == keycode_d)
		ft_player_move(data, data->player_row, data->player_col + 1, keycode, PLAYER_RIGHT_1);
	return (0);
}

int mlx_loop_hook_handler(t_data *data)
{
	ft_exit_animation(data);
	ft_player_animation(data);
	return 0;
}

int main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error("Game Data -> Malloc Error");
	data->argument_count = argc;
	data->map_name = argv[1];

	ft_validate_map(data);

	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, data->map_col_count * ASSET_SIZE, data->map_row_count * ASSET_SIZE, GAME_NAME);

	// burada düşmanı ayarlamış.
	
	ft_render_assets(data);
	ft_event_handler(data);
	return 0;
}
