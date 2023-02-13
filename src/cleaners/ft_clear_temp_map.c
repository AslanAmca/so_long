/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_temp_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:26:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 16:48:52 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_temp_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->temp_map == NULL || data->temp_map2 == NULL)
		return ;
	while (data->temp_map[i] != NULL)
	{
		free(data->temp_map[i]);
		free(data->temp_map2[i]);
		i++;
	}
	free(data->temp_map);
	free(data->temp_map2);
	data->temp_map = NULL;
	data->temp_map2 = NULL;
}
