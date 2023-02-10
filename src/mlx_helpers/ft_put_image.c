/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:37:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 07:42:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_image(t_data *data, char *img_name, int row, int col)
{
	int		width;
	int		height;
	void	*img;

	row = row * ASSET_SIZE;
	col = col * ASSET_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, img_name, &width, &height);
	if (img == NULL)
		ft_print_error("Image not found.");
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, col, row);
	free(img);
	img = NULL;
}
