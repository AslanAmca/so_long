/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:46:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:00:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_loop_hook_handler(t_data *data)
{
	ft_exit_animation(data);
	ft_player_animation(data);
	ft_enemy_animation(data);
	ft_enemy_move(data);
	return (0);
}
