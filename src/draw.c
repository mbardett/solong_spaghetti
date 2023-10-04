/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:47:10 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 14:25:03 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	draw_map(t_coordinate map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (j < map.map_lenght)
		{
			printf("%c ", map.map_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_animated_objs(t_game *game)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < game->dimensions->map_height)
	{
		i = 0;
		while (i < game->dimensions->map_lenght)
		{
			c = game->dimensions->map_matrix[j][i];
			draw_player(game, game->dimensions->x, game->dimensions->y,
				game->dimensions->map_matrix[j][i]);
			i++;
		}
		j++;
	}
}

int	draw(t_game *game)
{
	int		i;
	int		j;
	char	c;
	// char	*str;

	j = 0;
	ft_time(game);
	if (game->enemy.frame_count % 45 == 0)
		move_enemies(game);
	while (j < game->dimensions->map_height)
	{
		i = 0;
		while (i < game->dimensions->map_lenght)
		{
			c = game->dimensions->map_matrix[j][i];
			draw_level(game, j, i, c);
			i++;
		}
		j++;
	}
	return (1);
}

int	draw_level(t_game *game, int i, int j, char c)
{
	int	f = 1;
		if (c == '1')
			walls_anim(game, j * 32 *f, i * 32 * f );
		else if (c == 'f')
			candle_anim(game, j * 32 * f , i * 32 * f);
		else if (c == '0')
			floor_anim(game, j * 32 * f, i * 32 * f);
		else if (c == 'C')
			coll_anim(game, j * 32 * f, i * 32 * f);
		else if (c == 'E')
			door_anim(game, j * 32 * f, i * 32 * f);
		else if (c == 'P')
			player_anim(game, j * 32 * f, i * 32 * f);
		else if (c == 'M')
			enemy_anim(game, j * 32 * f , i * 32 * f);
		else if (c == 'x' || c == 'u' || c == 'b' || c == 'l' || c== 'r'|| c == 'w' || c == 'i' || c == 'S' || c == 'L' || c == 'O' || c == 'R')
		{
			gui_anim(game, j * 32, i * 32);
		}
	return (1);
}
