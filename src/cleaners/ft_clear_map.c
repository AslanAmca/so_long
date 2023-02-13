/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:27:09 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 16:48:02 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		return ;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}
