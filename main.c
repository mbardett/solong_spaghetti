/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:54:51 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 17:20:10 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lib.h"

//missing: 1)open all(in order to load all sprites)
//				as well as all the single functions for each game element
//			 2)mlx_loop_hook(to draw everything, INPUT-INDEPENDENT)
//			 3)mlx_key_hook(to trigger events on key press)
//			 3.5)mlx_hook(almost the same as mlx_key_hook)
//			 4)mlx_loop(to keep everything running and wait for
//				inputs/key press)
//			 5)DO WE WANT TO IMPLEMENT ENEMY AI??
int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	mouse_hook(int button, int x,int y, t_game *game)
{
	int	i = 0;
	int j = 0;
	
	if (button == 1)
	{
		printf("X = %d Y = %d\n", x,y);
		if (x > (game->dimensions->map_lenght - 2)* 32 && x < (game->dimensions->map_lenght -1) * 32 && y > (game->dimensions->map_height -3) * 32 && y < (game->dimensions->map_height -2)*32)
		{
			while (i < game->dimensions->map_height)
			{
				j = 0;
				while(j < game->dimensions->map_lenght)
				{
					if (game->dimensions->map_matrix[i][j] == 'w')
					{
						ft_save(game);
						mlx_string_put(game->mlx, game->mlx_win, j * 32, i * 32, 1315978,"Game Saved\n");
						// usleep(200000);
						return(0);
					}
					j++;
				}
				i++;
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_coordinate	data;
	t_game			game;
	// t_gui			gui;
	// read_file(argv[1], &data);

	if (check_arg_ber(argc, argv) == 1)
	{
		read_file(argv[1], &data);
		check_map_requirements(&data, &game);
		free(data.map_matrix);
		new_readfile(argv[1], &data);
	}
	// check_map_requirements(&data, &game);
	else if (check_arg_ber(argc, argv) == 2)
		read_file(argv[1], &data);
	game.dimensions = &data;
	// game.gui = gui;
	game_init(&game);
	open_all_sources(&game);
	game.level_init = 1;
	game.time = 1;
	mlx_mouse_hook(game.mlx_win, mouse_hook, &game);
	mlx_hook(game.mlx_win, 2, 0, deal_inputs, &game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, draw, (void *)&game);
	mlx_loop(game.mlx);
	write(1, "diobo\n", 6);
	return (0);
}
