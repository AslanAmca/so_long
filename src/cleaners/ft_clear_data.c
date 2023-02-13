/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:27:14 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 18:59:05 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_all_data(t_data *data)
{
	ft_clear_map(data);
	ft_clear_temp_map(data);
	ft_clear_enemy(data);
	ft_clear_mlx(data);
	ft_clear_only_data(data);
}
