/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:01:59 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 05:30:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_event_handler(t_data *data)
{
	mlx_hook(data->mlx_window, 17, 0, ft_close_handler, NULL);
	mlx_hook(data->mlx_window, 2, 1L << 0, ft_key_press_handler, data);
	mlx_loop_hook(data->mlx, ft_loop_hook_handler, data);
	mlx_loop(data->mlx);
}
