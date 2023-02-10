/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:56:09 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 06:05:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_windows(t_data *data)
{
	int	col;
	int	row;

	col = data->map_col_count * ASSET_SIZE;
	row = data->map_row_count * ASSET_SIZE;
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, col, row, GAME_NAME);
}
