/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:47:30 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 05:38:52 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_next_direction(t_data *data, t_enemy *temp)
{
	char	up_row;
	char	down_row;
	char	left_col;
	char	right_col;

	up_row = data->map[temp->enemy_row - 1][temp->enemy_col];
	down_row = data->map[temp->enemy_row + 1][temp->enemy_col];
	left_col = data->map[temp->enemy_row][temp->enemy_col - 1];
	right_col = data->map[temp->enemy_row][temp->enemy_col + 1];
	temp->enemy_direction = 0;
	if (temp->enemy_col > data->player_col
		&& (left_col == '0' || left_col == 'C' || left_col == 'P'))
		temp->enemy_direction = keycode_a;
	else if (temp->enemy_col < data->player_col
		&& (right_col == '0' || right_col == 'C' || right_col == 'P'))
		temp->enemy_direction = keycode_d;
	else if (temp->enemy_row > data->player_row
		&& (up_row == '0' || up_row == 'C' || up_row == 'P'))
		temp->enemy_direction = keycode_w;
	else if (temp->enemy_row < data->player_row
		&& (down_row == '0' || down_row == 'C' || down_row == 'P'))
		temp->enemy_direction = keycode_s;
}

void	ft_enemy_move_row(t_data *data, t_enemy *temp, int row)
{
	if (data->map[row][temp->enemy_col] == 'X')
		return ;
	else if (data->map[row][temp->enemy_col] == 'C')
	{
		data->map[temp->enemy_row][temp->enemy_col] = 'C';
		data->map[row][temp->enemy_col] = 'X';
		ft_put_image(data, COLLECTIBLE, temp->enemy_row, temp->enemy_col);
		ft_put_image(data, ENEMY_LEFT_1, row, temp->enemy_col);
	}
	else if (data->map[row][temp->enemy_col] == '0')
	{
		data->map[temp->enemy_row][temp->enemy_col] = '0';
		data->map[row][temp->enemy_col] = 'X';
		ft_put_image(data, GROUND, temp->enemy_row, temp->enemy_col);
		ft_put_image(data, ENEMY_LEFT_1, row, temp->enemy_col);
	}
	temp->enemy_row = row;
	if (data->map[temp->enemy_row][temp->enemy_col] ==
	data->map[data->player_row][data->player_col])
		ft_close_handler(data, "Game Over! Player touched an enemy patrol.\n");
}

void	ft_enemy_move_col(t_data *data, t_enemy *temp, int col, char *img_name)
{
	if (data->map[temp->enemy_row][col] == 'X')
		return ;
	else if (data->map[temp->enemy_row][col] == 'C')
	{
		data->map[temp->enemy_row][temp->enemy_col] = 'C';
		data->map[temp->enemy_row][col] = 'X';
		ft_put_image(data, COLLECTIBLE, temp->enemy_row, temp->enemy_col);
		ft_put_image(data, img_name, temp->enemy_row, col);
	}
	else if (data->map[temp->enemy_row][col] == '0')
	{
		data->map[temp->enemy_row][temp->enemy_col] = '0';
		data->map[temp->enemy_row][col] = 'X';
		ft_put_image(data, GROUND, temp->enemy_row, temp->enemy_col);
		ft_put_image(data, img_name, temp->enemy_row, col);
	}
	temp->enemy_col = col;
	if (data->map[temp->enemy_row][temp->enemy_col] ==
	data->map[data->player_row][data->player_col])
		ft_close_handler(data, "Game Over! Player touched an enemy patrol.\n");
}

void	ft_enemy_move(t_data *data)
{
	static int	counter = 0;
	int			limit;
	t_enemy		*temp;

	limit = 16000;
	temp = data->enemy;
	counter++;
	while (temp != NULL)
	{
		ft_enemy_next_direction(data, temp);
		if (temp->enemy_direction == keycode_w && counter == limit)
			ft_enemy_move_row(data, temp, temp->enemy_row - 1);
		if (temp->enemy_direction == keycode_s && counter == limit)
			ft_enemy_move_row(data, temp, temp->enemy_row + 1);
		if (temp->enemy_direction == keycode_a && counter == limit)
			ft_enemy_move_col(data, temp, temp->enemy_col - 1, ENEMY_LEFT_1);
		if (temp->enemy_direction == keycode_d && counter == limit)
			ft_enemy_move_col(data, temp, temp->enemy_col + 1, ENEMY_RIGHT_1);
		temp = temp->next;
	}
	if (counter > limit)
		counter = 0;
}
