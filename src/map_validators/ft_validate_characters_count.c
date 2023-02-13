/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_characters_count.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:54:53 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/12 18:59:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_characters_count(t_data *data)
{
	if (data->map_player_count < 1)
		ft_print_error("There are no player (P) on the map.");
	if (data->map_player_count > 1)
		ft_print_error("There can only be 1 player (P) on the map.");
	if (data->map_exit_count < 1)
		ft_print_error("There are no exit (E) on the map.");
	if (data->map_exit_count > 1)
		ft_print_error("There can only be 1 exit (E) on the map.");
	if (data->map_collectible_count < 1)
		ft_print_error("There are no collectible (C) on the map.");
	if (data->map_enemy_count < 1)
		ft_print_error("There are no enemy (X) on the map.");
}
