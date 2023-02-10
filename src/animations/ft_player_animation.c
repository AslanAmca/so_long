/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 06:46:44 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 05:43:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_up_animation(t_data *data)
{
	static int	counter = 0;

	if (counter == 0)
		ft_put_image(data, PLAYER_UP_1, data->player_row, data->player_col);
	else if (counter == 5000)
		ft_put_image(data, PLAYER_UP_2, data->player_row, data->player_col);
	else if (counter == 10000)
		ft_put_image(data, PLAYER_UP_3, data->player_row, data->player_col);
	else if (counter == 15000)
		ft_put_image(data, PLAYER_UP_4, data->player_row, data->player_col);
	else if (counter == 20000)
		ft_put_image(data, PLAYER_UP_5, data->player_row, data->player_col);
	else if (counter == 25000)
		ft_put_image(data, PLAYER_UP_6, data->player_row, data->player_col);
	counter++;
	if (counter == 30000)
		counter = 0;
}

static void	player_down_animation(t_data *data)
{
	static int	counter = 0;

	if (counter == 0)
		ft_put_image(data, PLAYER_DOWN_1, data->player_row, data->player_col);
	else if (counter == 5000)
		ft_put_image(data, PLAYER_DOWN_2, data->player_row, data->player_col);
	else if (counter == 10000)
		ft_put_image(data, PLAYER_DOWN_3, data->player_row, data->player_col);
	else if (counter == 15000)
		ft_put_image(data, PLAYER_DOWN_4, data->player_row, data->player_col);
	else if (counter == 20000)
		ft_put_image(data, PLAYER_DOWN_5, data->player_row, data->player_col);
	else if (counter == 25000)
		ft_put_image(data, PLAYER_DOWN_6, data->player_row, data->player_col);
	else if (counter == 30000)
		ft_put_image(data, PLAYER_DOWN_7, data->player_row, data->player_col);
	counter++;
	if (counter == 35000)
		counter = 0;
}

static void	player_left_animation(t_data *data)
{
	static int	counter = 0;

	if (counter == 0)
		ft_put_image(data, PLAYER_LEFT_1, data->player_row, data->player_col);
	else if (counter == 5000)
		ft_put_image(data, PLAYER_LEFT_2, data->player_row, data->player_col);
	else if (counter == 10000)
		ft_put_image(data, PLAYER_LEFT_3, data->player_row, data->player_col);
	else if (counter == 15000)
		ft_put_image(data, PLAYER_LEFT_4, data->player_row, data->player_col);
	else if (counter == 20000)
		ft_put_image(data, PLAYER_LEFT_5, data->player_row, data->player_col);
	else if (counter == 25000)
		ft_put_image(data, PLAYER_LEFT_6, data->player_row, data->player_col);
	else if (counter == 30000)
		ft_put_image(data, PLAYER_LEFT_7, data->player_row, data->player_col);
	counter++;
	if (counter == 35000)
		counter = 0;
}

static void	player_right_animation(t_data *data)
{
	static int	counter = 0;

	if (counter == 0)
		ft_put_image(data, PLAYER_RIGHT_1, data->player_row, data->player_col);
	else if (counter == 5000)
		ft_put_image(data, PLAYER_RIGHT_2, data->player_row, data->player_col);
	else if (counter == 10000)
		ft_put_image(data, PLAYER_RIGHT_3, data->player_row, data->player_col);
	else if (counter == 15000)
		ft_put_image(data, PLAYER_RIGHT_4, data->player_row, data->player_col);
	else if (counter == 20000)
		ft_put_image(data, PLAYER_RIGHT_5, data->player_row, data->player_col);
	else if (counter == 25000)
		ft_put_image(data, PLAYER_RIGHT_6, data->player_row, data->player_col);
	else if (counter == 30000)
		ft_put_image(data, PLAYER_RIGHT_7, data->player_row, data->player_col);
	counter++;
	if (counter == 35000)
		counter = 0;
}

void	ft_player_animation(t_data *data)
{
	if (data->player_direction == keycode_w)
		player_up_animation(data);
	if (data->player_direction == keycode_s)
		player_down_animation(data);
	if (data->player_direction == keycode_a)
		player_left_animation(data);
	if (data->player_direction == keycode_d)
		player_right_animation(data);
}
