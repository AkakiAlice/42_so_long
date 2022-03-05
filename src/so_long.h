/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:21 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/05 20:12:32 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".././libft/libft.h"
# include "mlx.h"

# define EXIT "./imgs/exit.xpm"
# define PLAYER_RIGHT "./imgs/player_right.xpm"
# define PLAYER_LEFT "./imgs/player_left.xpm"
# define FLOOR "./imgs/floor.xpm"
# define WALL "./imgs/wall.xpm"
# define COLLECT "./imgs/collect.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*floor;
	void	*player;
	void	*exit;
	void	*coin;
	void	*wall;
	char	**map;
	int		height;
	int		width;
	int		y;
	int		x;
	int		player_x;
	int		player_y;
	int		moves;
	int		points;
}			t_data;

int		error_msg(char *error_str);
int		check_args(int argc, char *argv);
int		check_items(t_data data);
int		check_walls(t_data data);
int		check_line(t_data data);
int		check_columns(t_data data);
int		shape_check(t_data data);
int		count_item(t_data data, char item);
void	free_matrix(char **ptr);
char	**create_matrix(char *file_name);
int		valid_line(char *temp);
int		valid_map(t_data data);
int		invalid_char(t_data data);
void	init_game(t_data *data);
int		close_game(t_data *data);
int		events(int keycode, t_data *data);
int		move_down(t_data *data);
int		move_up(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
int		load_map(t_data *data);
void	init_struct(t_data *data);
int		count_coins(t_data *data);
void	player_position(t_data *data);
int		close_game(t_data *data);
void	render_img(t_data *data, char c, int i, int j);

#endif