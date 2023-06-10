/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:47:10 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/21 17:31:01 by mbardett         ###   ########.fr       */
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
	char	*str;

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
	str = ft_itoa(game->moves_counter);
	mlx_string_put(game->mlx, game->mlx_win, game->dimensions->map_lenght * 32,
		(game->dimensions->map_height) - 1, TEXT_COLOR, str);
	free(str);
	return (1);
}

int	draw_level(t_game *game, int i, int j, char c)
{
	if (c == '1')
		walls_anim(game, j * 64, i * 64);
	else if (c == '0')
		floor_anim(game, j * 64, i * 64);
	else if (c == 'C')
		coll_anim(game, j * 64, i * 64);
	else if (c == 'E')
		door_anim(game, j * 64, i * 64);
	else if (c == 'P')
		player_anim(game, j * 64, i * 64);
	else if (c == 'M')
		enemy_anim(game, j * 64, i * 64);
	return (1);
}
