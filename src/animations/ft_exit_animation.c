/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 06:47:49 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 06:48:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_exit_animation(t_data *data)
{
	static int exit_counter = 0;
	static int exit_open_flag = 0;

	if (exit_open_flag == 1)
		return;
	if (data->map_collectible_count == 0)
	{
		ft_put_image_to_window(data, EXIT_OPEN, data->exit_row, data->exit_col);
		exit_open_flag = 1;
		return;
	}
	else if (exit_counter == 0)
		ft_put_image_to_window(data, EXIT_1, data->exit_row, data->exit_col);
	else if (exit_counter == 7000)
		ft_put_image_to_window(data, EXIT_2, data->exit_row, data->exit_col);
	else if (exit_counter == 10000)
		ft_put_image_to_window(data, EXIT_3, data->exit_row, data->exit_col);
	exit_counter++;
	if (exit_counter == 30000)
		exit_counter = 0;
}