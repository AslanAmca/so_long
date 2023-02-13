/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:27:04 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 16:52:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_mlx(t_data *data)
{
	if (data->mlx == NULL)
		return ;
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}
