/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 03:34:44 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_map(t_data *data)
{
	ft_validate_parameter(data);
	ft_read_and_fill_map(data);
	ft_validate_characters(data);
	ft_validate_characters_count(data);
	ft_validate_walls(data);
	ft_validate_rectangular(data);
	ft_validate_path(data);
}
