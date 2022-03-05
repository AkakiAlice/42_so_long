/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:23:52 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/04 20:58:13 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				render_img(data, '1', i, j);
			if (data->map[i][j] == '0')
				render_img(data, '0', i, j);
			if (data->map[i][j] == 'P')
				render_img(data, 'P', i, j);
			if (data->map[i][j] == 'E')
				render_img(data, 'E', i, j);
			if (data->map[i][j] == 'C')
				render_img(data, 'C', i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_img(t_data *data, char c, int i, int j)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->player, (32 * j), (32 * i));
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->coin, (32 * j), (32 * i));
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->exit, (32 * j), (32 * i));
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->wall, (32 * j), (32 * i));
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->floor, (32 * j), (32 * i));
}
