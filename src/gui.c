/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:35:42 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/12 18:29:01 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void    open_gui_imgs(t_game *game)
{
    game->gui->bcorner_ul = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_ul.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bcorner_ur = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Cnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bcorner_bl = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_bl.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bcorner_br = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_br.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->buh = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Brdr_up.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bbh = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Brdr_down.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->loadicon = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Loadicon.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bol = mlx_xpm_file_to_image(game->mlx, "/xpm/GUI/left.xpm", &game->img_size.img_width, &game->img_size.img_height);
    game->gui->bor = mlx_xpm_file_to_image(game->mlx, "/xpm/GUI/Crnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // game->gui.bcorner_ur = mlx_xpm_file_to_image(game->mlx, "/xpm/GUI/Crnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // game->gui.bcorner_ur = mlx_xpm_file_to_image(game->mlx, "/xpm/GUI/Crnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // game->gui.bcorner_ur = mlx_xpm_file_to_image(game->mlx, "/xpm/GUI/Crnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);

}


void    gui_anim(t_game *game, int j, int i)
{
// printf("i: %d \n", i );
   if (game->dimensions->map_matrix[i][j] == 'x' && (i == 1 || i == game->dimensions->map_height - 2) && j == 0)
        game->gui_icon = game->gui->bcorner_ul;
    else if (game->dimensions->map_matrix[i][j] == 'x' && (i == 1 || i == game->dimensions->map_height - 2 ) && j == game->dimensions->map_lenght)
        game->gui_icon = game->gui->bcorner_ur;
    else if (game->dimensions->map_matrix[i][j] == 'x'  && ( i  == game->dimensions->map_height - 4 || i  == game->dimensions->map_height) && j == 0)
        game->gui_icon = game->gui->bcorner_bl;
    else if (game->dimensions->map_matrix[i][j] == 'x' && ( i  == game->dimensions->map_height - 4  || i == game->dimensions->map_height)  && j  == game->dimensions->map_lenght)
        game->gui_icon = game->gui->bcorner_br;
    else if (game->dimensions->map_matrix[i][j] == 'u')
        game->gui_icon = game->gui->buh;
    else if (game->dimensions->map_matrix[i][j] == 'b')
        game->gui_icon = game->gui->bbh;
    else if (game->dimensions->map_matrix[i][j] == 'l')
    
    else if (game->dimensions->map_matrix[i][j] == 'L')
     game->gui_icon = game->gui->loadicon;
    // else if (game->dimensions->map_matrix[i][j] == 'r')
    
    // else if (game->dimensions->map_matrix[i][j] == 'w')

    // else if (game->dimensions->map_matrix[i][j] == 'i' && j = 1 && i == game->dimensions->map_height -3)

    // else if (game->dimensions->map_matrix[i][j] == 'i' && j = 1 && i == game->dimensions->map_height -2)

    // else if (game->dimensions->map_matrix[i][j] == 'i' && j = 2 )

    // else if (game->dimensions->map_matrix[i][j] == 'i' && j = 2 && i == game->dimensions->map_height -2)

    // else if (game->dimensions->map_matrix[i][j] == 'i' && j = 1 && i == game->dimensions->map_height -3)
    
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui_icon, j, i);
    // write(1, "xx\n", 3);
}

// void    draw_gui(t_game *game, int i, int j, char c)
// {
//     if (c == 'x')
//         gui_anim(game, j, i);
// }