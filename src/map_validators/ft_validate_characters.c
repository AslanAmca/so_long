/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_characters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:51:35 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 05:23:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_player_found_handler(t_data *data, int row, int col)
{
	data->map_player_count++;
	data->player_row = row;
	data->player_col = col;
	data->player_direction = keycode_d;
}

// Yeni düşman oluştur, aslında listenin bir elemanı olacak.
// düşmanın bulunduğu lokasyonu da dolduruyor.
// düşmanın img alanı burada doldurulmuyor.
static t_enemy	*ft_create_enemy(int row, int col)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (new_enemy == NULL)
		return (NULL);
	new_enemy->enemy_row = row;
	new_enemy->enemy_col = col;
	new_enemy->enemy_direction = keycode_a;
	new_enemy->next = NULL;
	return (new_enemy);
}

// Verilen linked list'e yeni düşmanı ekleyecek.
// Eğer liste boşsa o zaman yeni düşman ilk eleman olacak.
// Liste doluysa yeni eleman en son elaman olacak.
static void	ft_add_enemy(t_enemy **first_enemy, t_enemy *new_enemy)
{
	t_enemy	*temp;

	if (*first_enemy == NULL)
		*first_enemy = new_enemy;
	else
	{
		temp = *first_enemy;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_enemy;
	}
}

static void ft_enemy_found_handler(t_data *data, int row, int col)
{
	if (data->map[row + 1][col] == 'P' || data->map[row - 1][col] == 'P' || data->map[row][col - 1] == 'P' || data->map[row][col + 1] == 'P')
		ft_print_error("There must be space between the player and the enemy");

	data->map_enemy_count++;

	t_enemy	*new_enemy;

	new_enemy = ft_create_enemy(row, col);
	ft_add_enemy(&data->enemy, new_enemy);
	new_enemy = NULL;
}

static void ft_exit_found_handler(t_data *data, int row, int col)
{
	data->map_exit_count++;
	data->exit_row = row;
	data->exit_col = col;
}

static void ft_collectible_found_handler(t_data *data)
{
	data->map_collectible_count++;
	data->temp_map_collectible_count++;
	data->temp_map2_collectible_count++;
}

void ft_validate_characters(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				ft_player_found_handler(data, i, j);
			else if (data->map[i][j] == 'X')
				ft_enemy_found_handler(data, i, j);
			else if (data->map[i][j] == 'E')
				ft_exit_found_handler(data, i, j);
			else if (data->map[i][j] == 'C')
				ft_collectible_found_handler(data);
			else if (data->map[i][j] != '0' && data->map[i][j] != '1')
				ft_print_error("The map should only contain 0, 1, P, X, E, C");
			j++;
		}
		i++;
	}
}
