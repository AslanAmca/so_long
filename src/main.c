/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:42 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:02:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_data(t_data *data, int argument_count, char *map_name)
{
	data->argument_count = argument_count;
	data->map_name = map_name;
	data->map_row_count = 0;
	data->map_col_count = 0;
	data->map_player_count = 0;
	data->map_enemy_count = 0;
	data->map_exit_count = 0;
	data->map_collectible_count = 0;
	data->temp_map_player_can_exit = 0;
	data->temp_map_collectible_count = 0;
	data->temp_map2_player_can_exit = 0;
	data->temp_map2_collectible_count = 0;
	data->player_row = 0;
	data->player_col = 0;
	data->player_direction = 0;
	data->player_move_count = 0;
	data->exit_row = 0;
	data->exit_col = 0;
	data->map = NULL;
	data->temp_map = NULL;
	data->temp_map2 = NULL;
	data->enemy = NULL;
	data->mlx = NULL;
	data->mlx_window = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error("Game Data -> Malloc Error");
	ft_init_data(data, argc, argv[1]);
	ft_validate_map(data);
	ft_create_window(data);
	ft_render_assets(data);
	ft_event_handler(data);
	ft_close_handler(data, "Game Finish!\n");
	return (EXIT_SUCCESS);
}
