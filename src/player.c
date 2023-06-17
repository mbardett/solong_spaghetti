/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:12:39 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/17 22:10:31 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_player_imgs(t_game *game)
{
	game->player.frame_count = 0;
	game->player.p_frame1 = mlx_xpm_file_to_image(game->mlx, "xpm/player/player01.xpm", &game->img_size.img_width, &game->img_size.img_height);
	game->player.p_frame2 = mlx_xpm_file_to_image(game->mlx, "xpm/player/player02.xpm", &game->img_size.img_width, &game->img_size.img_height);
	game->player.p_frame3 = mlx_xpm_file_to_image(game->mlx, "xpm/player/player03.xpm", &game->img_size.img_width, &game->img_size.img_height);
	game->player.p_frame4 = mlx_xpm_file_to_image(game->mlx, "xpm/player/player04.xpm", &game->img_size.img_width, &game->img_size.img_height);
	game->player.p_frame5 = mlx_xpm_file_to_image(game->mlx, "xpm/player/player05.xpm", &game->img_size.img_width, &game->img_size.img_height);
}

void	player_anim(t_game *game, int j, int i)
{
	if (game->player.frame_count <= 5)
		game->player_mesh = game->player.p_frame1;
	else if (game->player.frame_count <= 10)
		game->player_mesh = game->player.p_frame2;
	else if (game->player.frame_count <= 15)
		game->player_mesh = game->player.p_frame3;
	else if (game->player.frame_count <= 20)
		game->player_mesh = game->player.p_frame4;
	else if (game->player.frame_count <= 25)
		game->player_mesh = game->player.p_frame5;
	else if (game->player.frame_count == 30)
		game->player.frame_count = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player_mesh, j, i);
}

// yeah, now it seems a waste of time but I swear it was longer before
void	draw_player(t_game *game, int i, int j, char c)
{
	if (c == 'P')
		player_anim(game, j, i);
}
