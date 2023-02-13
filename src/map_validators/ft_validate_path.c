/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:17:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 18:58:45 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_dfs_algorithm(t_data *data, int row, int col)
{
	if (data->temp_map[row][col] == '1'
	|| data->temp_map[row][col] == 'X'
	|| data->temp_map[row][col] == '.')
		return ;
	if (data->temp_map[row][col] == 'E')
		data->temp_map_player_can_exit = 1;
	if (data->temp_map[row][col] == 'C')
		data->temp_map_collectible_count--;
	data->temp_map[row][col] = '.';
	ft_dfs_algorithm(data, row, col + 1);
	ft_dfs_algorithm(data, row, col - 1);
	ft_dfs_algorithm(data, row + 1, col);
	ft_dfs_algorithm(data, row - 1, col);
}

static void	ft_dfs_algorithm_with_exit(t_data *data, int row, int col)
{
	if (data->temp_map2[row][col] == '1'
	|| data->temp_map2[row][col] == 'X'
	|| data->temp_map2[row][col] == '.')
		return ;
	if (data->temp_map2[row][col] == 'E')
	{
		data->temp_map2_player_can_exit = 1;
		return ;
	}
	if (data->temp_map2[row][col] == 'C')
		data->temp_map2_collectible_count--;
	data->temp_map2[row][col] = '.';
	ft_dfs_algorithm_with_exit(data, row, col + 1);
	ft_dfs_algorithm_with_exit(data, row, col - 1);
	ft_dfs_algorithm_with_exit(data, row + 1, col);
	ft_dfs_algorithm_with_exit(data, row - 1, col);
}

void	ft_validate_path(t_data *data)
{
	ft_dfs_algorithm(data, data->player_row, data->player_col);
	ft_dfs_algorithm_with_exit(data, data->player_row, data->player_col);
	if (data->temp_map_player_can_exit != 1)
		ft_print_error(data,
			"Not a valid path as the exit can't be reached.");
	if (data->temp_map_collectible_count != data->temp_map2_collectible_count)
		ft_print_error(data,
			"Exit is preventing the collection.");
	if (data->temp_map_collectible_count != 0)
		ft_print_error(data,
			"Not a valid way as collectibles are not collected.");
	ft_clear_temp_map(data);
}
