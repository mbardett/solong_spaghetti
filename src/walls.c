/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:10:02 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/15 13:30:42 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_walls(t_game *game)
{
	game->wall.framecount = 0;
	game->wall_mesh = mlx_xpm_file_to_image(game->mlx, "xpm/Wall.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	walls_anim(t_game *game, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->wall_mesh, j, i);
}

void	draw_walls(t_game *game, int i, int j, char c)
{
	if (c == '1')
		walls_anim(game, j, i);
}
