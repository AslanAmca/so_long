/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:08:28 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/31 18:40:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_error(char *error_message)
{
	ft_print_string("Error!\n");
	ft_print_string(error_message);
	ft_print_string("\n");
	exit(EXIT_FAILURE);
}
