/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:47:10 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/14 16:17:29 by mbardett         ###   ########.fr       */
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
	// str = ft_itoa(game->moves_counter);
	// mlx_string_put(game->mlx, game->mlx_win, game->dimensions->map_lenght * 32,
	// 	(game->dimensions->map_height) - 1, TEXT_COLOR, str);
	// free(str);
	return (1);
}

int	draw_level(t_game *game, int i, int j, char c)
{
		if (c == '1')
			walls_anim(game, j * 32 , i * 32 );
		else if (c == 'f')
			candle_anim(game, j * 32 , i * 32);
		else if (c == '0')
			floor_anim(game, j * 32, i * 32);
		else if (c == 'C')
			coll_anim(game, j * 32, i * 32);
		else if (c == 'E')
			door_anim(game, j * 32, i * 32);
		else if (c == 'P')
			player_anim(game, j * 32, i * 32);
		else if (c == 'M')
			enemy_anim(game, j * 32 , i * 32);
		else if (c == 'x' || c == 'u' || c == 'b' || c == 'l' || c== 'r'|| c == 'w' || c == 'i' || c == 'S' || c == 'L' || c == 'O' || c == 'R')
		{
			// write(1, "gui\n",4);
			// printf("i %d j %d \n", i, j);
			gui_anim(game, j * 32, i * 32);
			// gui_anim(game, j , i);
			// write(1, "OPS\n",4);
		}
		// else if (c == 'x')
		// 	printf("%d %d\n", i, j);
		// 	gui_anim(game, j, i );
		// else if (c == 'u')
		// 	gui_anim(game, j , i );
		// else if (c == 'b')		
		// 	gui_anim(game, j , i );
		// else if (c == 'l')
		// 	gui_anim(game, j , i );			
		// else if (c == 'r')
		// 	gui_anim(game, j , i );
		// else if (c == 'R')
		// 	gui_anim(game, j , i );
		// else if (c == 'L')
		// 	gui_anim(game, j , i );
		// else if ( c == 'O')
		// 	gui_anim(game, j , i );
		// else if (c == 'S')
		// 	gui_anim(game, j , i );
	return (1);
}
