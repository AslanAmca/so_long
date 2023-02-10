/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:55:41 by aaslan            #+#    #+#             */
/*   Updated: 2023/02/10 05:57:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define GAME_NAME "so_long"
# define ASSET_SIZE 64

// Player Assets
# define PLAYER_UP_1 "assets/player_up_1.xpm"
# define PLAYER_UP_2 "assets/player_up_2.xpm"
# define PLAYER_UP_3 "assets/player_up_3.xpm"
# define PLAYER_UP_4 "assets/player_up_4.xpm"
# define PLAYER_UP_5 "assets/player_up_5.xpm"
# define PLAYER_UP_6 "assets/player_up_6.xpm"
# define PLAYER_DOWN_1 "assets/player_down_1.xpm"
# define PLAYER_DOWN_2 "assets/player_down_2.xpm"
# define PLAYER_DOWN_3 "assets/player_down_3.xpm"
# define PLAYER_DOWN_4 "assets/player_down_4.xpm"
# define PLAYER_DOWN_5 "assets/player_down_5.xpm"
# define PLAYER_DOWN_6 "assets/player_down_6.xpm"
# define PLAYER_DOWN_7 "assets/player_down_7.xpm"
# define PLAYER_LEFT_1 "assets/player_left_1.xpm"
# define PLAYER_LEFT_2 "assets/player_left_2.xpm"
# define PLAYER_LEFT_3 "assets/player_left_3.xpm"
# define PLAYER_LEFT_4 "assets/player_left_4.xpm"
# define PLAYER_LEFT_5 "assets/player_left_5.xpm"
# define PLAYER_LEFT_6 "assets/player_left_6.xpm"
# define PLAYER_LEFT_7 "assets/player_left_7.xpm"
# define PLAYER_RIGHT_1 "assets/player_right_1.xpm"
# define PLAYER_RIGHT_2 "assets/player_right_2.xpm"
# define PLAYER_RIGHT_3 "assets/player_right_3.xpm"
# define PLAYER_RIGHT_4 "assets/player_right_4.xpm"
# define PLAYER_RIGHT_5 "assets/player_right_5.xpm"
# define PLAYER_RIGHT_6 "assets/player_right_6.xpm"
# define PLAYER_RIGHT_7 "assets/player_right_7.xpm"
# define PLAYER_MOVE_COUNT "assets/player_move_count.xpm"

// Enemy Assets
# define ENEMY_LEFT_1 "assets/enemy_left_1.xpm"
# define ENEMY_LEFT_2 "assets/enemy_left_2.xpm"
# define ENEMY_RIGHT_1 "assets/enemy_right_1.xpm"
# define ENEMY_RIGHT_2 "assets/enemy_right_2.xpm"

// Exit Assets
# define EXIT_1 "assets/exit_1.xpm"
# define EXIT_2 "assets/exit_2.xpm"
# define EXIT_3 "assets/exit_3.xpm"
# define EXIT_OPEN "assets/exit_open.xpm"

// Collectible & Ground & Wall Assets
# define COLLECTIBLE "assets/collectible.xpm"
# define GROUND "assets/ground.xpm"
# define WALL "assets/wall.xpm"

typedef struct s_enemy {
	int				enemy_row;
	int				enemy_col;
	int				enemy_direction;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_data
{
	t_enemy *enemy;

	int		argument_count;
	char	*map_name;

	char	**map;
	int		map_row_count;
	int		map_col_count;
	int		map_player_count;
	int		map_enemy_count;
	int		map_exit_count;
	int		map_collectible_count;

	// temp 1 for dfs
	char	**temp_map;
	int		temp_map_player_can_exit;
	int		temp_map_collectible_count;

	// temp 2 for dfs with exit
	char	**temp_map2;
	int		temp_map2_player_can_exit;
	int		temp_map2_collectible_count;

	// Player
	int		player_row;
	int		player_col;
	int		player_direction;
	int		player_move_count;

	// Exıt
	int		exit_row;
	int		exit_col;

	// mlx
	void	*mlx;
	void	*mlx_window;
}	t_data;

enum e_keycode
{
	keycode_a = 97,
	keycode_d = 100,
	keycode_w = 119,
	keycode_s = 115,
	keycode_esc = 65307
};

// utilities
void	ft_print_string(char *string);
void	ft_print_error(char *error_message);
int		ft_strlen(char *string);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

// validators
void	ft_validate_parameter(t_data *data);
void	ft_validate_characters(t_data *data);
void	ft_validate_characters_count(t_data *data);
void	ft_validate_walls(t_data *data);
void	ft_validate_rectangular(t_data *data);
void	ft_validate_path(t_data *data);
void	ft_validate_map(t_data *data);

// moves
void ft_player_move(t_data *data, int next_row, int next_col, int keycode, char *asset_name);
void ft_enemy_move(t_data *data);

// animations
void ft_player_animation(t_data *data);
void ft_exit_animation(t_data *data);
void ft_enemy_animation(t_data *data);

void	ft_add_enemy(t_enemy **first_enemy, t_enemy *new_enemy);
t_enemy	*ft_create_enemy(int row, int col);

// bunlara bakacağız.
void ft_read_and_fill_map(t_data *data);
void	ft_create_windows(t_data *data);
void ft_put_image(t_data *data, char *img_name, int row, int col);
void ft_render_assets(t_data *data);
void ft_event_handler(t_data *data);

#endif
