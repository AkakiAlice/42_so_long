/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:15:44 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/04 20:34:05 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	events(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_game(data);
	if (keycode == A || keycode == LEFT_ARROW)
		move_left(data);
	if (keycode == D || keycode == RIGHT_ARROW)
		move_right(data);
	if (keycode == W || keycode == UP_ARROW)
		move_up(data);
	if (keycode == S || keycode == DOWN_ARROW)
		move_down(data);
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		if (data->map[data->player_y][data->player_x - 1] == 'E'
			&& data->points != 0)
			return (load_map(data));
		if (data->map[data->player_y][data->player_x - 1] == 'C')
			data->points--;
		if (data->map[data->player_y][data->player_x - 1] == 'E'
			&& data->points == 0)
		{
			ft_printf("Thanks for playing! :)\n");
			close_game(data);
		}
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_LEFT,
				&data->x, &data->y);
		ft_printf("Movements: %i\n", ++data->moves);
		load_map(data);
		data->player_x = data->player_x - 1;
	}
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		if (data->map[data->player_y][data->player_x + 1] == 'E'
			&& data->points != 0)
			return (load_map(data));
		if (data->map[data->player_y][data->player_x + 1] == 'C')
			data->points--;
		if (data->map[data->player_y][data->player_x + 1] == 'E'
			&& data->points == 0)
		{
			ft_printf("Thanks for playing! :)\n");
			close_game(data);
		}
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		mlx_destroy_image(data->mlx_ptr, data->player);
		data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_RIGHT,
				&data->x, &data->y);
		ft_printf("Movements: %i\n", ++data->moves);
		load_map(data);
		data->player_x = data->player_x + 1;
	}
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		if (data->map[data->player_y - 1][data->player_x] == 'E'
			&& data->points != 0)
			return (load_map(data));
		if (data->map[data->player_y - 1][data->player_x] == 'C')
			data->points--;
		if (data->map[data->player_y - 1][data->player_x] == 'E'
			&& data->points == 0)
		{
			ft_printf("Thanks for playing! :)\n");
			close_game(data);
		}
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		ft_printf("Movements: %i\n", ++data->moves);
		load_map(data);
		data->player_y = data->player_y - 1;
	}
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		if (data->map[data->player_y + 1][data->player_x] == 'E'
			&& data->points != 0)
			return (load_map(data));
		if (data->map[data->player_y + 1][data->player_x] == 'C')
			data->points--;
		if (data->map[data->player_y + 1][data->player_x] == 'E'
			&& data->points == 0)
		{
			ft_printf("Thanks for playing! :)\n");
			close_game(data);
		}
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		ft_printf("Movements: %i\n", ++data->moves);
		load_map(data);
		data->player_y = data->player_y + 1;
	}
	return (0);
}
