/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:43:10 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/12 15:43:07 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# ifndef TEXT_COLOR
#  define TEXT_COLOR  0xFFFFFF
# endif

# define RAND_MAX 5

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_coordinate
{
	int			x;
	int			y;
	int			map_height;
	int			map_lenght;
	char		**map_matrix;
}	t_coordinate;

typedef struct s_wall
{
	int			framecount;
	void		*w_img;
	void		*w_candle1;
	void		*w_candle2;
	void		*w_candle3;
	void		*w_candle4;
	void		*w_candle5;
	void		*w_innerv;
	void		*w_innerh;
}	t_wall;

typedef struct s_player
{
	int			frame_count;
	int			player_y_coords;
	int			player_x_coords;
	void		*p_frame1;
	void		*p_frame2;
	void		*p_frame3;
	void		*p_frame4;
	void		*p_frame5;
	void		*p_frame6;
	void		*p_frame7;
	void		*p_frame8;
}	t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				frame_count;
	void			*e_frame0;
	void			*e_frame1;
	void			*e_frame2;
	void			*e_frame3;
	void			*e_frame4;
	void			*e_frame5;
	void			*e_frame6;
	void			*e_frame7;
	void			*e_frame8;
	void			*e_frame9;
	void			*this_enemy;
	struct s_enemy	*next_enemy;
}	t_enemy;

// typedef struct  s_list
// {
// 	t_enemy	*this_enemy;
// 	struct s_list	*next;
// }	t_list;

typedef struct s_coll
{
	int		frame_count;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
}	t_coll;

typedef struct s_exit_door
{
	int		framecount;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
}	t_exit_door;

typedef struct s_floor
{
	int		framecount;
	void	*img1;
}	t_floor;

typedef struct s_img
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_gui
{
	//upper left corner
	void	*bcorner_ul;
	void	*bcorner_ur;
	void	*bcorner_bl;
	void	*bcorner_br;
	//	upper border txr
	void	*buh;
	//  bottom border txr
	void	*bbh;
	// left border txr
	void	*bol;
	//right border txr
	void	*bor;
	//text window, as the border of the gamescreen, needs 4 corners + horizontal and verical borders; 
	void 	*wuh;
	void	*wbh;
	void	*wol;
	void	*wor;
	void	*wcul;
	void	*wcur;
	void	*wcbl;
	void	*wcbr;
	//ICONS
	void	*saveicon;
	void	*loadicon;
	void	*optionsicon;
	void	*resticon;
	//INVENTORY: 4 slots,  closed backpack, when clicked opens 
	void	*backp_ul;
	void	*backp_ur;
	void	*backp_bl;
	void	*backp_br;
	void	*inv_ul;
	void	*inv_ur;
	void	*inv_bl;
	void	*inv_br;

}	t_gui;




//dunno if this is gonna work, need to see how to implement this;
//typedef struct s_death_screen
//{
//
//}	t_death_screen;

typedef struct s_game
{
	t_coordinate		*dimensions;
	t_img				img_size;
	t_player			player;
	t_enemy				enemy;
	t_coll				coll;
	t_exit_door			exit_door;
	t_wall				wall;
	t_floor				floor;
	t_gui				*gui;

	int					moves_counter;
	int					enemy_number;
	void				*enemy_mesh;
	void				*player_mesh;
	void				*door_mesh;
	void				*coll_mesh;
	void				*wall_mesh;
	void				*floor_mesh;
	void				*gui_icon;
	void				*mlx;
	void				*mlx_win;
	int					total_collectibles;
	int					current_collectibles;
	int					level_init;
	int					time;
}	t_game;

//ft_itoa.c
char	*ft_revstr(char *s);
int		get_num(int n);
int		get_sign(int n, char *s, int *i);
char	*ft_itoa(int n);
//ft_utils.c
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_display_error(int error_type);
//spostata nel main
int		end_game(t_game *game);
//gnl.c + gn;_so_long.c
int		check_conditions(char *str);
char	*read_save_line(char *str);
char	*next_loop(char *str);
char	*already_read(int fd, char *buffer, char *temp, char *str);
char	*gnl_so_long(int fd);
char	*get_next_line(int fd, char **line);
//map_data.c
int		get_length_helper(int fd, int length_check);
int		get_length(char *str);
int		get_height(char *str);
void	fill_matrix(char *to_fill, char *lines);
void	read_file(char *nome_file, t_coordinate *data);
void	new_readfile(char *nome_file, t_coordinate *data);



//map_checks.c
void	check_walls_n_spawns(t_coordinate data);
void	check_collectibles_n_exit(t_coordinate data, t_game *game);
void	check_player(t_coordinate *data);
void	check_map_requirements(t_coordinate *data, t_game *game);
//floor_n_walls.c
void	open_floor_img(t_game *game);
void	floor_anim(t_game *game, int i, int j);
void	draw_floor(t_game *game, int i, int j, char c);
//walls.c
void	draw_walls(t_game *game, int i, int j, char c);
void	open_walls(t_game *game);
void	walls_anim(t_game *game, int i, int j);
void	candle_anim(t_game *game, int j, int i);
//door.c
void	open_door_img(t_game *game);
void	door_anim(t_game *game, int i, int j);
void	draw_door(t_game *game, int i, int j, char c);
//player.c
void	open_player_imgs(t_game *game);
void	player_anim(t_game *game, int j, int i);
void	draw_player(t_game *game, int i, int j, char c);
//enemy.c
void	open_enemy_imgs(t_game *game);
void	enemy_anim(t_game *game, int j, int i);
void	draw_enemy(t_game *game, int i, int j, char c);
//movement.c
int		x_dir(int key);
int		y_dir(int key);
void	check_player_movement(t_game *game, int x, int y);
void	move_player(t_game *game, int key);
void	move_player_aux(t_game *game, int key);
//enemy_movement.c
int		en_x_dir(int key);
int		en_y_dir(int key);
void	move_enemies_helper(t_game *game, int x, int y);
void	move_enemies(t_game *game);
//enemy_utils.c currently not using any of this functions
char	*ft_strchr(char *s, int c);
//int		**enemy_new_coords(t_game *game);
//coll.c
void	open_coll_imgs(t_game *game);
void	coll_anim(t_game *game, int j, int i);
void	draw_coll(t_game *game, int i, int j, char c);
//draw.c
int		draw_level(t_game *game, int i, int j, char c);
int		draw(t_game *game);
//inputs.c
int		return_keycode(int key);
int		deal_inputs(int key, t_game *game);
int		ft_time(t_game *game);
void	refresh_frames(t_game *game);
//game_init.c
void	open_all_sources(t_game *game);
int		check_arg_ber(int argc, char **argv);
void	game_init(t_game *game);
//gui.c
void    open_gui_imgs(t_game *game);
void    gui_anim(t_game *game, int j, int i);
void    draw_gui(t_game *game, int i, int j, char c);
//list_management.c
// t_enemy	*ft_lstnew(int x, int y);
// t_enemy	*ft_lstlast(t_enemy *lst);
// void	ft_lstadd_back(t_enemy *lst, t_enemy *new);
//DEBUG
void	draw_map(t_coordinate map);
#endif
