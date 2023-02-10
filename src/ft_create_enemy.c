/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 05:35:38 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 06:03:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*ft_create_enemy(int row, int col)
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

void	ft_add_enemy(t_enemy **first_enemy, t_enemy *new_enemy)
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
