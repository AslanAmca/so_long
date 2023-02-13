/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_parameter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:28:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:01:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_parameter(t_data *data)
{
	int	offset;

	offset = ft_strlen(data->map_name) - 4;
	if (data->argument_count == 1)
		ft_print_error("Map parameter was not sent.");
	if (data->argument_count > 2)
		ft_print_error("More than 2 parameters cannot be entered.");
	if (data->map_name == NULL || *data->map_name == '\0')
		ft_print_error("Map parameter cannot be null or empty.");
	if (ft_strcmp(data->map_name + offset, ".ber") != 0)
		ft_print_error("Map file must be '.ber' extension.");
}
