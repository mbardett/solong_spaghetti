/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:01:06 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 12:50:42 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_door_img(t_game *game)
{
	game->exit_door.framecount = 0;
	game->exit_door.img1 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/Wall-bricks-wooden-door-closed.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->exit_door.img2 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/door-open.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	door_anim(t_game *game, int j, int i)
{
	if (game->current_collectibles == 0)
	game->door_mesh = game->exit_door.img2;
	else 
		game->door_mesh = game->exit_door.img1;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->door_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_door(t_game *game, int i, int j, char c)
{
	if (c == 'E')
		door_anim(game, j, i);
}
