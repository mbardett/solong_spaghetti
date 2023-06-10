/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_n_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:43:43 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 13:29:47 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_floor_img(t_game *game)
{
	game->floor.framecount = 0;
	game->floor_mesh = mlx_xpm_file_to_image(game->mlx, "xpm/Floor.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	floor_anim(t_game *game, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->floor_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_floor(t_game *game, int i, int j, char c)
{
	if (c == '0')
		floor_anim(game, j, i);
}
