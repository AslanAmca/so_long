/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:01:59 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 07:43:17 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	key_press_handler(int keycode, t_data *data)
{
	if (keycode == keycode_esc)
		close_handler(data);
	if (keycode == keycode_w)
		ft_player_move(data, data->player_row - 1, data->player_col, keycode);
	if (keycode == keycode_s)
		ft_player_move(data, data->player_row + 1, data->player_col, keycode);
	if (keycode == keycode_a)
		ft_player_move(data, data->player_row, data->player_col - 1, keycode);
	if (keycode == keycode_d)
		ft_player_move(data, data->player_row, data->player_col + 1, keycode);
	return (0);
}

static int	mlx_loop_hook_handler(t_data *data)
{
	ft_exit_animation(data);
	ft_player_animation(data);
	ft_enemy_animation(data);
	ft_enemy_move(data);
	return (0);
}

void	ft_event_handler(t_data *data)
{
	mlx_hook(data->mlx_window, 17, 0, close_handler, data);
	mlx_hook(data->mlx_window, 2, 1L << 0, key_press_handler, data);
	mlx_loop_hook(data->mlx, mlx_loop_hook_handler, data);
	mlx_loop(data->mlx);
}
