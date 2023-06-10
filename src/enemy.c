/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:07:32 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/10 14:23:34 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_enemy_imgs(t_game *game)
{
	game->enemy.frame_count = 0;
	game->enemy.e_frame0 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost00.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame1 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost01.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame2 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost02.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame3 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost03.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame4 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost04.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame5 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost05.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame6 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost06.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame7 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost07.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame8 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost08.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->enemy.e_frame9 = mlx_xpm_file_to_image(game->mlx, "xpm/ghost xpm/Ghost09.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

//Writing down this just çause it might be usefule later, eventually...
// if You want to run an animation, just exec the next commented lines in the
// *****_anim function
// 	else if (game->enemy.frame_count == 75)
// 		game->enemy_mesh = game->enemy.e_frame2;
// 	else if (game->enemy.frame_count == 90)
// 		game->enemy_mesh = game->enemy.e_frame3;
// 	ETC ETC ETC
void	enemy_anim(t_game *game, int j, int i)
{
	if (game->enemy.frame_count <= 4)
		game->enemy_mesh = game->enemy.e_frame0;
	else if (game->enemy.frame_count <= 8)
		game->enemy_mesh = game->enemy.e_frame1;
	else if (game->enemy.frame_count <= 12)
		game->enemy_mesh = game->enemy.e_frame2;
	else if (game->enemy.frame_count <= 16)
		game->enemy_mesh = game->enemy.e_frame3;
	else if (game->enemy.frame_count <= 20)
		game->enemy_mesh = game->enemy.e_frame4;
	else if (game->enemy.frame_count <= 24)
		game->enemy_mesh = game->enemy.e_frame5;
	else if (game->enemy.frame_count <= 28)
		game->enemy_mesh = game->enemy.e_frame6;
	else if (game->enemy.frame_count <= 32)
		game->enemy_mesh = game->enemy.e_frame7;
	else if (game->enemy.frame_count <= 36)
		game->enemy_mesh = game->enemy.e_frame8;
	else if (game->enemy.frame_count <= 40)
		game->enemy_mesh = game->enemy.e_frame9;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_enemy(t_game *game, int i, int j, char c)
{
	if (c == 'M')
		enemy_anim(game, j, i);
}
