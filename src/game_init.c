/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:39:46 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/10 13:56:32 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	open_all_sources(t_game *game)
{
	open_walls(game);
	open_floor_img(game);
	open_door_img(game);
	open_coll_imgs(game);
	open_enemy_imgs(game);
	open_player_imgs(game);
}

//checks correct number of args and correct file extension of the last
//argument;ft_display_error currently outputting 5 different Errors,
//go read the comment a wise man wrote before its definition.
int	check_arg_ber(int argc, char **argv)
{
	int	i;
	int	file_exists;

	i = 0;
	file_exists = open(argv[1], O_RDONLY);
	if (file_exists < 0)
		ft_display_error(666);
	if (argc != 2)
		ft_display_error(1);
	i = ft_strlen(argv[1]);
	if (!strcmp(argv[1], "save.ber"))
		return (2);
	if (argv[1][i - 1] != 'r' || argv[1][i -2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
		ft_display_error(0);
	return (1);
}

void	game_init(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	y = game->dimensions->map_lenght * 64;
	x = game->dimensions->map_height * 64;
	game->mlx_win = mlx_new_window(game->mlx, y, x, "so_long");
	game->moves_counter = 0;
}
