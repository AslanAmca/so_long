/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:27:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/13 16:53:19 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_enemy(t_data *data)
{
	t_enemy	*current;
	t_enemy	*next;

	current = data->enemy;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	data->enemy = NULL;
}
