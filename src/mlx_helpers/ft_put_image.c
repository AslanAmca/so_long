/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:37:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:00:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_image(t_data *data, char *img_name, int row, int col)
{
	int		width;
	int		height;

	row = row * ASSET_SIZE;
	col = col * ASSET_SIZE;
	data->mlx_image = mlx_xpm_file_to_image
		(data->mlx, img_name, &width, &height);
	if (data->mlx_image == NULL)
		ft_print_error("Mlx image not found.");
	mlx_put_image_to_window
	(data->mlx, data->mlx_window, data->mlx_image, col, row);
	mlx_destroy_image(data->mlx, data->mlx_image);
}
