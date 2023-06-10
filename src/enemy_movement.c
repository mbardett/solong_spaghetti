/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:09:39 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/20 15:32:41 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	en_x_dir(int key)
{
	int	x_direction;

	x_direction = 0;
	if (key % 11 == 0)
		x_direction = 1;
	if (key % 7 == 0)
		x_direction = -1;
	return (x_direction);
}

int	en_y_dir(int key)
{
	int	y_direction;

	y_direction = 0;
	if (key % 3 == 0)
		y_direction = 1;
	if (key % 5 == 0)
		y_direction = -1;
	return (y_direction);
}

//might add a level difficulty system, based on terminal input at the start
//of the game, which multiplies the enemies movement rate(the & in draw(game))
void	move_enemies(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->dimensions->map_height)
	{
		x = -1;
		while (++x < game->dimensions->map_lenght)
		{
			if (game->dimensions->map_matrix[y][x] == 'M')
			{
				move_enemies_helper(game, x, y);
			}
		}
	}
}

void	move_enemies_helper(t_game *game, int x, int y)
{
	int	r;
	int	nx;
	int	ny;

	r = rand();
	nx = x + en_x_dir(r);
	r = rand();
	ny = y + en_y_dir(r);
	if (game->dimensions->map_matrix[ny][nx] == '0'
		|| game->dimensions->map_matrix[ny][nx] == 'P')
	{
		if (game->dimensions->map_matrix[ny][nx] == 'P')
		{
			write (1, "YOU DIED!\n", 11);
			end_game(game);
		}
		game->dimensions->map_matrix[ny][nx] = 'M';
		game->dimensions->map_matrix[y][x] = '0';
	}
}
