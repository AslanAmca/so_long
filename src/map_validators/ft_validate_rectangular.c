/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_rectangular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:40:18 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/06 23:56:57 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_rectangular(t_data *data)
{
	int	row_index;
	int	row_col_count;

	row_index = 0;
	while (row_index < data->map_row_count)
	{
		row_col_count = ft_strlen(data->map[row_index]);
		if (row_col_count != data->map_col_count)
			ft_print_error("The map must be rectangular.");
		row_index++;
	}
}
