/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_parameter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:28:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 03:33:58 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_validate_parameter(t_data *data)
{
	int		map_len;
	char	*map_extension;

	if (data->argument_count == 1)
		ft_print_error("Map parameter was not sent.");
	if (data->argument_count > 2)
		ft_print_error("More than 2 parameters cannot be entered.");
	if (data->map_name == NULL || *data->map_name == '\0')
		ft_print_error("Map parameter cannot be null or empty.");
	map_len = ft_strlen(data->map_name);
	map_extension = data->map_name + map_len - 4;
	if (ft_strcmp(map_extension, ".ber") != 0)
		ft_print_error("Map file must be '.ber' extension.");
}
