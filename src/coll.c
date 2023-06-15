/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:19:50 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 13:01:13 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_coll_imgs(t_game *game)
{
	game->coll.frame_count = 0;
	game->coll.img1 = mlx_xpm_file_to_image(game->mlx, "xpm/Collectibles/key01.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->coll.img2 = mlx_xpm_file_to_image(game->mlx, "xpm/Collectibles/key02.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->coll.img3 = mlx_xpm_file_to_image(game->mlx, "xpm/Collectibles/key03.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->coll.img4 = mlx_xpm_file_to_image(game->mlx, "xpm/Collectibles/key04.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->coll.img5 = mlx_xpm_file_to_image(game->mlx, "xpm/Collectibles/key05.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	coll_anim(t_game *game, int j, int i)
{
	if (game->coll.frame_count <= 8)
		game->coll_mesh = game->coll.img1;
	else if (game->coll.frame_count <= 16)
		game->coll_mesh = game->coll.img2;
	else if (game->coll.frame_count <= 24)
		game->coll_mesh = game->coll.img3;
	else if (game->coll.frame_count <= 32)
		game->coll_mesh = game->coll.img4;
	else if (game->coll.frame_count <= 40)
		game->coll_mesh = game->coll.img5;
	else if (game->coll.frame_count < 80)
		game->coll_mesh = game->coll.img1;
	else if (game->coll.frame_count == 80)
		game->coll.frame_count = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->coll_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_coll(t_game *game, int i, int j, char c)
{
	if (c == 'C')
		coll_anim(game, j, i);
}
