/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:10:02 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 12:46:40 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_walls(t_game *game)
{
	game->wall.framecount = 0;
	game->wall.w_img = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/Wall-bricks-tileable.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	// write(1, "t\n", 2);

	game->wall.w_candle1 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/wall-brick-candle1.png.xpm",
			&game->img_size.img_width , &game->img_size.img_height);
	// write(1, "1\n", 2);

	game->wall.w_candle2 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/wall-brick-candle2.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
		// write(1, "2\n", 2);

	game->wall.w_candle3 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/wall-brick-candle3.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	// write(1, "3\n", 2);

	game->wall.w_candle4 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/wall-brick-candle4.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
		// write(1, "4\n", 2);

	game->wall.w_candle5 = mlx_xpm_file_to_image(game->mlx, "xpm/Levels/wall-brick-candle5.png.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
		// write(1, "5\n", 2);

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
		game->candle_mesh = game->wall.w_candle1;
	else if (game->wall.framecount <= 20)
		game->candle_mesh = game->wall.w_candle2;
	else if (game->wall.framecount <= 30)
		game->candle_mesh = game->wall.w_candle3;
	else if (game->wall.framecount <= 40)
		game->candle_mesh = game->wall.w_candle4;
	else if (game->wall.framecount <= 50)
		game->candle_mesh = game->wall.w_candle5;
	else if (game->wall.framecount == 60)
		game->wall.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->candle_mesh, j, i);
}

void	draw_walls(t_game *game, int i, int j, char c)
{
	if (c == '1')
		walls_anim(game, j, i);		
}

void	draw_candle(t_game *game, int j, int i, char c)
{
	if (c == 'f')
		candle_anim(game, j, i);
}
