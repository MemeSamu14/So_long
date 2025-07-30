/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:56:01 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:21 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// funzione che elimina il display
void	free_display(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->graphic.front_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.front_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.back_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.back_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.left_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.left_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.right_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.right_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.ground_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.ground_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.tree_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.coin_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.coin_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.coin_3_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.exit_1_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.exit_2_img);
	mlx_destroy_image(data->mlx_ptr, data->graphic.enemy_img);
}

// assegna il percorse delle immagini nella struttura
void	img_paths(t_mlx_data *data)
{
	data->graphic.front_1_path = "./sprites/front_1.xpm";
	data->graphic.front_2_path = "./sprites/front_2.xpm";
	data->graphic.back_1_path = "./sprites/back_1.xpm";
	data->graphic.back_2_path = "./sprites/back_2.xpm";
	data->graphic.left_1_path = "./sprites/left_1.xpm";
	data->graphic.left_2_path = "./sprites/left_2.xpm";
	data->graphic.right_1_path = "./sprites/right_1.xpm";
	data->graphic.right_2_path = "./sprites/right_2.xpm";
	data->graphic.ground_1_path = "./sprites/Ground_1.xpm";
	data->graphic.ground_2_path = "./sprites/Ground_2.xpm";
	data->graphic.tree_1_path = "./sprites/Tree_1.xpm";
	data->graphic.coin_1_path = "./sprites/c_1.xpm";
	data->graphic.coin_2_path = "./sprites/c_2.xpm";
	data->graphic.coin_3_path = "./sprites/c_3.xpm";
	data->graphic.exit_1_path = "./sprites/exit_1.xpm";
	data->graphic.exit_2_path = "./sprites/exit_2.xpm";
	data->graphic.enemy_path = "./sprites/enemy.xpm";
}

// funzione che assegna alle immagini il proprio path
void	paths_to_img(t_mlx_data *data)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	paths_to_img_2(data, width, height);
	data->graphic.front_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.front_1_path, &width, &height);
	data->graphic.front_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.front_2_path, &width, &height);
	data->graphic.back_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.back_1_path, &width, &height);
	data->graphic.back_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.back_2_path, &width, &height);
	data->graphic.left_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.left_1_path, &width, &height);
	data->graphic.left_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.left_2_path, &width, &height);
	data->graphic.right_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.right_1_path, &width, &height);
	data->graphic.right_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.right_2_path, &width, &height);
	data->graphic.enemy_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.enemy_path, &width, &height);
}

// funzione che carica la mappa a schermo
void	load_map(t_mlx_data *data, int i, int j)
{
	int	random;

	random = 0;
	while (j < data->matrix_len)
	{
		i = 0;
		while (i < (int)ft_strlen(data->map[0]))
		{
			random = rng(j);
			load_img(data, i, j, random);
			i++;
		}
		j++;
	}
}

// funzione che implementa la funzione load map 
void	load_img(t_mlx_data *data, int i, int j, int random)
{
	static int	counter;

	counter++;
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.tree_1_img, i * 32, j * 32);
	else if (data->map[j][i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.ground_1_img, i * 32, j * 32);
	else if (data->map[j][i] == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.ground_2_img, i * 32, j * 32);
	else if (data->map[j][i] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.coin_1_img, i * 32, j * 32);
	else if (data->map[j][i] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.coin_2_img, i * 32, j * 32);
	else if (data->map[j][i] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.enemy_img, i * 32, j * 32);
	else
		load_img_2(data, i, j, counter);
}
