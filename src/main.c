/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:42 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 00:53:28 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	ft_render_assets(data);
	ft_event_handler(data);
	return 0;
}
