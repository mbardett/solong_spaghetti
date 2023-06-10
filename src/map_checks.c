/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:15:45 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/20 14:27:24 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

//as the name implies...checks for perimetral 1s and for the presence of
//the right "characters"inside the map
void	check_walls_n_spawns(t_coordinate data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	if (data.map_height < 3 || data.map_lenght < 3)
		ft_display_error(3);
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_lenght)
		{
			c = data.map_matrix[y][x];
			if ((y == 0 || y == data.map_height - 1) && c != '1')
				ft_display_error(2);
			if ((x == 0 || x == data.map_lenght - 1) && c != '1')
				ft_display_error(2);
			if (c != '1' && c != 'E' && c != 'C' && c != '0' && c != 'P'
				&& c != 'M')
				ft_display_error(3);
			x++;
		}
		y++;
	}
}

//as the name implies...checks the existence of both Exit and Collectibles,
//and eventual enemies,then sets the variable total_collectibles
//inside the struct
void	check_collectibles_n_exit(t_coordinate data, t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_lenght)
		{
			if (data.map_matrix[y][x] == 'C')
				game->total_collectibles++;
			if (data.map_matrix[y][x] == 'E')
				i++;
			if (data.map_matrix[y][x] == 'M')
				game->enemy_number++;
			x++;
		}
		y++;
	}
	game->current_collectibles = game->total_collectibles;
	if (i < 1 || game->total_collectibles < 1)
		ft_display_error(3);
}

void	check_player(t_coordinate *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			if (data->map_matrix[y][x] == 'P')
			{
				i++;
				data->y = y;
				data->x = x;
			}
			x++;
		}
		y++;
	}
	if (i != 1)
		ft_display_error(3);
}

void	check_map_requirements(t_coordinate *data, t_game *game)
{
	check_walls_n_spawns(*data);
	check_player(data);
	check_collectibles_n_exit(*data, game);
}
