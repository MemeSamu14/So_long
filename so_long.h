/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:26:39 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 18:52:44 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "utils/utils.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

//dovrebbe essere per inserire le immagini immagini
typedef struct s_data
{
	void		*front_1_img;
	void		*front_2_img;
	void		*back_1_img;
	void		*back_2_img;
	void		*left_1_img;
	void		*left_2_img;
	void		*right_1_img;
	void		*right_2_img;
	void		*ground_1_img;
	void		*ground_2_img;
	void		*tree_1_img;
	void		*coin_1_img;
	void		*coin_2_img;
	void		*coin_3_img;
	void		*exit_1_img;
	void		*exit_2_img;
	void		*enemy_img;
	char		*exit_1_path;
	char		*exit_2_path;
	char		*coin_1_path;
	char		*coin_2_path;
	char		*coin_3_path;
	char		*front_1_path;
	char		*front_2_path;
	char		*back_1_path;
	char		*back_2_path;
	char		*left_1_path;
	char		*left_2_path;
	char		*right_1_path;
	char		*right_2_path;
	char		*ground_1_path;
	char		*ground_2_path;
	char		*tree_1_path;
	char		*enemy_path;
	int			img_length;
	int			img_width;
}	t_data;

//per gestire gli input da tastiera 
//egestire la finestra e la connessione con la libreria
typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			matrix_len;
	t_data		graphic;
	int			x_player;
	int			y_player;
	int			x_exit;
	int			y_exit;
	int			moves;
	int			coins;
	int			coin_taken;
}			t_mlx_data;
//aggiungere all struttura soprastante la matrice della mappa xche` 
// almeno la passi in giro piu` facilmente
int		handle_input(int keysym, t_mlx_data *data);
int		handle_mouse_input(t_mlx_data *data);
char	**map_allocation(int *len, char **av);
char	**fill_matrix(t_mlx_data *data, char **av);
int		map_checks(t_mlx_data *data);
int		map_lines_not_equal(char **map, int matrix_len);
int		map_border_valid(char **map, int matrix_len);
int		coll_exit_p1_checker(char **map, int matrix_len);
int		essential(char **map, int matrix_len, const char c);
void	map_truncate(char **map, int matrix_len);
void	free_matrix(char **matrix, int len);
char	**strdup_marix(char **map, int matrix_len);
void	print_matrix(char **matrix, int len);
void	flood_fill(char **matrix, int x, int y);
int		path_check(t_mlx_data *data);
void	img_paths(t_mlx_data *data);
void	paths_to_img(t_mlx_data *data);
void	paths_to_img_2(t_mlx_data *data, int width, int height);
void	img_from_sprites_init(t_mlx_data *data);
void	free_display(t_mlx_data *data);
void	load_img(t_mlx_data *data, int i, int j, int random);
void	load_img_2(t_mlx_data *data, int i, int j, int counter);
void	load_img_3(t_mlx_data *data, int i, int j, int counter);
void	load_map(t_mlx_data *data, int i, int j);
void	free_all(t_mlx_data *data);
int		so_long(t_mlx_data data, char **av);
void	random_if(t_mlx_data *data, int i, int j, int random);
void	random_matrix(t_mlx_data *data);
void	movement_right(t_mlx_data *data);
void	movement_left(t_mlx_data *data);
void	movement_up(t_mlx_data *data);
void	movement_down(t_mlx_data *data);
int		movement_right_2(t_mlx_data *data);
int		movement_left_2(t_mlx_data *data);
int		movement_up_2(t_mlx_data *data);
int		movement_down_2(t_mlx_data *data);
int		rng(int j);
int		rng_background(int j, int i);
int		valid_characters(t_mlx_data *data);
void	*map_malloc(t_mlx_data *data, char **av);

#endif