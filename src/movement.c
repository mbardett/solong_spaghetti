/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:50:40 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/20 15:33:42 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	x_dir(int key)
{
	int	x_direction;

	x_direction = 0;
	if (key == 2)
		x_direction = 1;
	if (key == 0)
		x_direction = -1;
	return (x_direction);
}

int	y_dir(int key)
{
	int	y_direction;

	y_direction = 0;
	if (key == 1)
		y_direction = 1;
	if (key == 13)
		y_direction = -1;
	return (y_direction);
}

void	check_player_movement(t_game *game, int x, int y)
{
	if (game->dimensions->map_matrix[y][x] == 'M')
	{
		write (1, "YOU DIED!\n", 11);
		end_game(game);
	}
	if (game->dimensions->map_matrix[y][x] == 'C')
		game->current_collectibles--;
	if (game->dimensions->map_matrix[y][x] == 'E' && game->current_collectibles
		== 0)
	{
		write(1, "YOU WON!\n", 10);
		end_game(game);
	}
	if (game->dimensions->map_matrix[y][x] != 'E' ||
		game->dimensions->map_matrix[y][x] != 'M')
	{
		game->dimensions->map_matrix[game->dimensions->y][game->dimensions->x]
			= '0';
		game->dimensions->map_matrix[y][x] = 'P';
		game->moves_counter++;
	}
	game->dimensions->x = x;
	game->dimensions->y = y;
}

void	move_player_aux(t_game *game, int key)
{
	int		x;
	int		y;
	int		c;
	char	**matrix;

	c = game->current_collectibles;
	matrix = game->dimensions->map_matrix;
	x = game->dimensions->x + x_dir(key);
	y = game->dimensions->y + y_dir(key);
	if (matrix[y][x] != '1')
	{
		if (!(matrix[y][x] == 'E' && c != 0))
			check_player_movement(game, x, y);
	}
}

//might consider adding something after the move_player_aux call
//in order to consider the consequences of the move(like replacing a coll
// sprite or displaying "level cleared"etc etc).
void	move_player(t_game *game, int key)
{
	int		c;
	char	**matrix;

	c = game->current_collectibles;
	matrix = game->dimensions->map_matrix;
	move_player_aux(game, key);
}
