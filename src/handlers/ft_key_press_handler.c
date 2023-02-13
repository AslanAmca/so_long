/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:46:14 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 05:40:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key_press_handler(int keycode, t_data *data)
{
	if (keycode == keycode_esc)
		ft_close_handler(data, "Bye Bye!\n");
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
