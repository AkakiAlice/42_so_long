/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:04:53 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/04 20:30:37 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

static int	count_width(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			j++;
		}
		i++;
	}
	return (j);
}

void	init_struct(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->moves = 0;
	data->points = 0;
	player_position(data);
	count_coins(data);
	data->height = count_height(data);
	data->width = count_width(data);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR,
			&data->x, &data->y);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &data->x, &data->y);
	data->coin = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT,
			&data->x, &data->y);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &data->x, &data->y);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_LEFT,
			&data->x, &data->y);
}

int	count_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->points++;
			j++;
		}
		i++;
	}
	return (data->points);
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
