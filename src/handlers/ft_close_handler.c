/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:34:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 06:03:08 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_enemy(t_data *data)
{
	t_enemy	*current;
	t_enemy	*next;

	current = data->enemy;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	data->enemy = NULL;
}

static void	ft_clear_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

static void	ft_clear_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}

static void	ft_clear_data(t_data *data)
{
	ft_clear_enemy(data);
	ft_clear_map(data);
	ft_clear_mlx(data);
	free(data);
	data = NULL;
}

int	ft_close_handler(t_data *data, char *message)
{
	ft_print_string(message);
	ft_clear_data(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
