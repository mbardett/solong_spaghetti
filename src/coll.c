/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:19:50 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 13:56:47 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_coll_imgs(t_game *game)
{
	game->coll.frame_count = 0;
	game->coll_mesh = mlx_xpm_file_to_image(game->mlx, "xpm/Collectible.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	coll_anim(t_game *game, int j, int i)
{
	game->coll.img1 = game->coll_mesh;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->coll_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_coll(t_game *game, int i, int j, char c)
{
	if (c == 'C')
		coll_anim(game, j, i);
}
