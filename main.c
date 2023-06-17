/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:54:51 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/17 22:28:18 by mbardett         ###   ########.fr       */
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

int ft_wtext_handler(t_game *game)
{
	
	int i = 0;
	int j = 0;
	int	wlen = 0;
	int whei = 0;
	int iw = 0;
	int jw = 0;
	char *buffer = NULL;
	while (i < game->dimensions->map_height)
	{
		if (game->dimensions->map_matrix[i][j] == 'w')
		{
			iw = i;
			jw = j;
			mlx_string_put(game->mlx, game->mlx_win, 2 * 32, (game->dimensions->map_height -3) * 32, 1315978, game->gui.text);
			printf(" %c \n", game->dimensions->map_matrix[i][j]);
			// printf("wi =%d  wj =%d  \n", i, j);
			break;
		}
		j = 0;
		while(j < game->dimensions->map_lenght)
			j++;
		i++;
	}
	while (game->dimensions->map_matrix[i][j] == 'w')
	{
		j++;
		wlen++;
	}
	while (game->dimensions->map_matrix[i][j] == 'w')
	{
		i++;
		whei++;	
	}				
	// if (ft_strlen(game->gui.text) > (size_t)wlen)
	// {
	// 	i = 0;
	// 	j = 0;
	// 	buffer = malloc(sizeof(char) * ((wlen + 1) * (whei +1)));
	// 	while (i < whei)
	// 	{
	// 		j = 0;
	// 		while(j < wlen)	
	// 		{
	// 			buffer[j] = game->gui.text[i];
	// 			j++;			
	// 		}
	// 		buffer[j] = '\n';
	// 		i++;
	// 	}
	// 	buffer[j] = '\0';
	// 	// mlx_string_put(game->mlx, game->mlx_win, j * 32, i * 32, 1315978, buffer);
	// 	mlx_string_put(game->mlx, game->mlx_win, jw * 32, ( game->dimensions->map_height - whei) * 32, 1315978, buffer);
	// 	printf("wi =%d  wj =%d  \n", iw, jw);
	// 	j = j * i;
	// 	i = 0;
	// 	free(buffer);
	// 	buffer = malloc(sizeof(char) * ft_strlen(game->gui.text));
	// 	while (game->gui.text)
	// 	{
	// 		buffer[i] = game->gui.text[j];
	// 		i++;
	// 		j++;
	// 	}
	// 	buffer[i] = '\0';
	// 	game->gui.text = buffer;
	// }
	// else
	// {
	// 	if (game->gui.text)
	// 	{
			// mlx_string_put(game->mlx, game->mlx_win, jw * 32, (iw + 1) * 32, 1315978, game->gui.text);
			// printf("wi =%d  wj =%d  \n", iw, jw);
		// }
	// }
	if (buffer != NULL)
		free(buffer);
	return (0);
}

int	mouse_hook(int button, int x,int y, t_game *game)
{	
	if (button == 1)
	{
		// printf("X = %d Y = %d\n", x,y);
		if (x > (game->dimensions->map_lenght - 2)* 32 && x < (game->dimensions->map_lenght -1) * 32 && y > (game->dimensions->map_height -3) * 32 && y < (game->dimensions->map_height -2)*32)
		{
			ft_save(game);		
		}
		//next else if is very scary T_T
		// else if (x > (game->dimensions->map_lenght - 2)* 32 && x < (game->dimensions->map_lenght -1) * 32 && y > (game->dimensions->map_height -2) * 32 && y < (game->dimensions->map_height -1)*32)
		// {
		// 	ft_load(game);
		// }
	}
	ft_wtext_handler(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_coordinate	data;
	t_game			game;

	if (check_arg_ber(argc, argv) == 2)
	{
		read_file(argv[1], &data);
		check_map_requirements(&data, &game);
		free(data.map_matrix);
		new_readfile(argv[1], &data);
	}
	else
		read_file(argv[1], &data);
	game.dimensions = &data;
	game_init(&game);
	open_all_sources(&game);
	game.gui.text = calloc(3, 1);
	game.level_init = 1;
	game.time = 1;
	mlx_mouse_hook(game.mlx_win, mouse_hook, &game);
	mlx_hook(game.mlx_win, 2, 0, deal_inputs, &game);
	mlx_hook(game.mlx_win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, ft_wtext_handler, (void *)&game);
	mlx_loop_hook(game.mlx, draw, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
