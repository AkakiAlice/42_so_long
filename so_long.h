/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:21 by alida-si          #+#    #+#             */
/*   Updated: 2022/02/26 00:31:03 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
}			t_data;

int		error_msg(char *error_str);
int		check_args(int argc, char *argv);
int		valid_items(t_data data);
int		check_walls(t_data data);
int		check_line(t_data data);
int		check_columns(t_data data);
int		shape_check(t_data data);
int		count_item(t_data data, char item);
void	free_matrix(char **ptr);

#endif