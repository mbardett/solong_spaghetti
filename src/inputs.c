/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:33:23 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 17:47:09 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	return_keycode(int key)
{
	return (key == 0 || key == 1 || key == 2 || key == 13 || key == 53);
}

//in order to return only the keyboard inputs we want to handle
int	deal_inputs(int key, t_game *game)
{
	if (return_keycode(key))
	{
		if (key == 53)
			end_game(game);
		else
			move_player(game, key);
	}
	return (1);
}

//ft_time called inside mlx_loop(game->mlx,draw(game), void)
//in order to measure when to change sprites and to control
// enemies movement
int	ft_time(t_game *game)
{
	game->player.frame_count++;
	game->enemy.frame_count++;
	game->coll.frame_count++;
	game->time++;
	return (1);
}
