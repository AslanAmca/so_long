/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_fill_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:34:41 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/09 03:35:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read_map(int map_fd)
{
	char	*string;
	char	buffer;
	int		readed_byte;
	int		i;

	string = malloc(1024);
	readed_byte = 61;
	i = 0;
	while (readed_byte != 0)
	{
		readed_byte = read(map_fd, &buffer, 1);
		if (readed_byte <= 0)
			break ;
		string[i] = buffer;
		i++;
	}
	string[i] = '\0';
	close(map_fd);
	return (string);
}

static void	ft_fill_map(t_data *data, char *map_string)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	col_count = 0;
	data->map = ft_split(map_string, '\n');
	data->temp_map = ft_split(map_string, '\n');
	data->temp_map2 = ft_split(map_string, '\n');
	while (data->map[row_count] != NULL)
		row_count++;
	while (data->map[0][col_count] != '\0' && data->map[0][col_count] != '\n')
		col_count++;
	data->map_row_count = row_count;
	data->map_col_count = col_count;
}

void	ft_read_and_fill_map(t_data *data)
{
	int		map_fd;
	char	*map_string;

	map_fd = open(data->map_name, O_RDONLY);
	if (map_fd < 3)
		ft_print_error("Map file not found.");
	map_string = ft_read_map(map_fd);
	if (*map_string == '\0')
		ft_print_error("Map file is empty.");
	ft_fill_map(data, map_string);
	free(map_string);
	map_string = NULL;
}
