/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:10:02 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/11 17:19:30 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_walls(t_game *game)
{
	game->wall.framecount = 0;
	game->wall.w_img = mlx_xpm_file_to_image(game->mlx, "xpm/Wall-bricks-tileable.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->wall.w_candle1 = mlx_xpm_file_to_image(game->mlx, "xpm/wall-brick-candle1.png.xpm",
			&game->img_size.img_width , &game->img_size.img_height);
	game->wall.w_candle2 = mlx_xpm_file_to_image(game->mlx, "xpm/wall-brick-candle2.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->wall.w_candle3 = mlx_xpm_file_to_image(game->mlx, "xpm/wall-brick-candle3.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->wall.w_candle4 = mlx_xpm_file_to_image(game->mlx, "xpm/wall-brick-candle4.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->wall.w_candle5 = mlx_xpm_file_to_image(game->mlx, "xpm/wall-brick-candle5.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	walls_anim(t_game *game, int j, int i)
{
	game->wall_mesh = game->wall.w_img;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->wall_mesh, j, i);
}

void	candle_anim(t_game *game, int j, int i)
{
	if (game->wall.framecount <= 10)
		game->wall_mesh = game->wall.w_candle1;
	else if (game->wall.framecount <= 20)
		game->wall_mesh = game->wall.w_candle2;
	else if (game->wall.framecount <= 30)
		game->wall_mesh = game->wall.w_candle3;
	else if (game->wall.framecount <= 40)
		game->wall_mesh = game->wall.w_candle4;
	else if (game->wall.framecount <= 50)
		game->wall_mesh = game->wall.w_candle5;
	else if (game->wall.framecount == 60)
		game->wall.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->wall_mesh, j, i);
}

void	draw_walls(t_game *game, int i, int j, char c)
{
	if (c == '1')
		walls_anim(game, j, i);
	else if (c == 'f')
		candle_anim(game,i , j);
}
