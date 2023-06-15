/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_n_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:43:43 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 12:48:28 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_floor_img(t_game *game)
{
	game->floor.framecount = 0;
	game->floor.img1 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/newfloor.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	floor_anim(t_game *game, int j, int i)
{
	game->floor_mesh = game->floor.img1;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->floor_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_floor(t_game *game, int i, int j, char c)
{
	if (c == '0')
		floor_anim(game, j, i);
}
