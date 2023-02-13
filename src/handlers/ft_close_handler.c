/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:34:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 16:59:59 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	ft_close_handler(t_data *data, char *message)
{
	ft_print_string(message);
	ft_clear_all_data(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
