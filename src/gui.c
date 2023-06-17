/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:35:42 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/17 16:51:41 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void    open_gui_imgs(t_game *game)
{
    // int i = 0;
    
    game->gui.bcorner_ul = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_ul.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bcorner_ul);
    game->gui.bcorner_ur = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Cnr_ur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bcorner_ur);
    game->gui.bcorner_bl = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_bl.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bcorner_bl);
    game->gui.bcorner_br = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Crnr_br.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bcorner_br);
    game->gui.buh = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Brdr_up.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.buh);
    game->gui.bbh = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Brdr_down.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bbh);
    game->gui.loadicon = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Loadicon.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.loadicon);
    game->gui.saveicon = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Saveicon.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.saveicon);
    game->gui.resticon = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Resticon.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.resticon);
    game->gui.optionsicon = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/Optionsicon.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.optionsicon);
    game->gui.bol = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/left.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bol);
    game->gui.bor = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/right.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.bor);
    game->gui.backp_ul = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/bpul.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.backp_ul);
    game->gui.backp_ur = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/bpur.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.backp_ur);
    game->gui.backp_bl = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/bpbl.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.backp_bl);
    game->gui.backp_br = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/bpdr.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.backp_br);
    game->gui.textw = mlx_xpm_file_to_image(game->mlx, "xpm/GUI/twin.xpm", &game->img_size.img_width, &game->img_size.img_height);
    // printf("loaded gui img n %p\n", game->gui.textw);
}


void    gui_anim(t_game *game, int j, int i)
{
    int a;
    int b;

    a = i / 32;
    b = j / 32;
// printf("i: %d \n", i );
    // if (game->dimensions->map_matrix[i][j] == 'x' && (i == 1 || i == game->dimensions->map_height - 2) && j == 0)
    //     game->gui_icon = game->gui->bcorner_ul;
    // else if (game->dimensions->map_matrix[i][j] == 'x' && (i == 1 || i == game->dimensions->map_height - 2 ) && j == game->dimensions->map_lenght)
    //     game->gui_icon = game->gui->bcorner_ur;
    // else if (game->dimensions->map_matrix[i][j] == 'x'  && ( i  == game->dimensions->map_height - 4 || i  == game->dimensions->map_height) && j == 0)
    //     game->gui_icon = game->gui->bcorner_bl;
    // else if (game->dimensions->map_matrix[i][j] == 'x' && ( i  == game->dimensions->map_height - 4  || i == game->dimensions->map_height)  && j  == game->dimensions->map_lenght)
    //     game->gui_icon = game->gui->bcorner_br;
    // else if (game->dimensions->map_matrix[i][j] == 'u')
    //     game->gui_icon = game->gui->buh;
    // else if (game->dimensions->map_matrix[i][j] == 'b')
    //     game->gui_icon = game->gui->bbh;
    // else if (game->dimensions->map_matrix[i][j] == 'l')
    //     game->gui_icon = game->gui->bol;
    // else if (game->dimensions->map_matrix[i][j] == 'r')
    //     game->gui_icon  = game->gui->bor;
    // else if (game->dimensions->map_matrix[i][j] == 'L')
    //     game->gui_icon = game->gui->loadicon;
    // else if (game->dimensions->map_matrix[i][j] == 'S')
    //     game->gui_icon = game->gui->loadicon;
    // else if (game->dimensions->map_matrix[i][j] == 'O')
    //     game->gui_icon = game->gui->loadicon;
    // else if (game->dimensions->map_matrix[i][j] == 'R')
    //     game->gui_icon = game->gui->loadicon;
    // else if (game->dimensions->map_matrix[i][j] == 'i' && i == game->dimensions->map_height -3 && j == 2)
    //     game->gui_icon = game->gui->backp_ur;
    // else if (game->dimensions->map_matrix[i][j] == 'i' && i == game->dimensions->map_height -3 && j == 1)
    //     game->gui_icon = game->gui->backp_ul;
    // else if (game->dimensions->map_matrix[i][j] == 'i' && i == game->dimensions->map_height -2 && j == 2)
    //     game->gui_icon = game->gui->backp_br;
    // else if (game->dimensions->map_matrix[i][j] == 'i' && i == game->dimensions->map_height -2 && j == 1)
    //     game->gui_icon = game->gui->backp_bl;
    // else if (game->dimensions->map_matrix[i][j] == 'w')
    //     game->gui_icon = game->gui->textw;
    // mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui_icon, j, i);
    // write(1, "xx\n", 3);
    if (game->dimensions->map_matrix[a][b] == 'x' && (a == 0 || a == game->dimensions->map_height - 4) && b == 0)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bcorner_ul, j, i);
    if (game->dimensions->map_matrix[a][b] == 'x' && (a == 0 || a == game->dimensions->map_height - 4 ) && b == game->dimensions->map_lenght -1)
         mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bcorner_ur, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'x'  && ( a  == game->dimensions->map_height - 5 || a  == game->dimensions->map_height -1) && b == 0)
         mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bcorner_bl, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'x' && ( a == game->dimensions->map_height - 5  || a == game->dimensions->map_height -1)  && b == game->dimensions->map_lenght -1)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bcorner_br, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'u')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.buh, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'b')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bbh, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'l')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bol, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'r')
         mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.bor, j, i);
    if (game->dimensions->map_matrix[a][b] == 'L')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.loadicon, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'S')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.saveicon, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'O')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.optionsicon, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'R')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.resticon, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'i' && a == game->dimensions->map_height -3 && b == 2)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.backp_ur, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'i' && a == game->dimensions->map_height -3 && b == 1)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.backp_ul, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'i' && a == game->dimensions->map_height -2 && b == 2)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.backp_br, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'i' && a == game->dimensions->map_height -2 && b == 1)
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.backp_bl, j ,i);
    if (game->dimensions->map_matrix[a][b] == 'w')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui.textw, j, i);
    // mlx_put_image_to_window(game->mlx, game->mlx_win, game->gui_icon, j, i);    
}

void    draw_gui(t_game *game, int i, int j, char c)
{
    if (c == 'x')
        gui_anim(game, j, i);
}