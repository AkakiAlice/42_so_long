/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:45:33 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/04 20:31:02 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	init_struct(data);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->width * 32,
			data->height * 32, "SO_LONG");
	mlx_hook(data->mlx_win, 02, 1L << 0, events, data);
	mlx_hook(data->mlx_win, 17, 0L, close_game, data);
	mlx_loop_hook(data->mlx_ptr, &load_map, data);
	mlx_loop(data->mlx_ptr);
}
