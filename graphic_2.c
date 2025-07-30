/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:35:22 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:16 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paths_to_img_2(t_mlx_data *data, int width, int height)
{
	data->graphic.ground_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.ground_1_path, &width, &height);
	data->graphic.ground_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.ground_2_path, &width, &height);
	data->graphic.tree_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.tree_1_path, &width, &height);
	data->graphic.coin_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.coin_1_path, &width, &height);
	data->graphic.coin_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.coin_2_path, &width, &height);
	data->graphic.coin_3_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.coin_3_path, &width, &height);
	data->graphic.exit_1_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.exit_1_path, &width, &height);
	data->graphic.exit_2_img = mlx_xpm_file_to_image(data->mlx_ptr, \
								data->graphic.exit_2_path, &width, &height);
}

void	load_img_2(t_mlx_data *data, int i, int j, int counter)
{
	if (data->map[j][i] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.coin_3_img, i * 32, j * 32);
	else if (data->map[j][i] == 'P')
	{
		if (counter % 70000 < 35000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.front_1_img, i * 32, j * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.front_2_img, i * 32, j * 32);
	}
	else if (data->map[j][i] == 'R')
	{
		if (counter % 70000 < 35000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.right_2_img, i * 32, j * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.right_1_img, i * 32, j * 32);
	}
	else
		load_img_3(data, i, j, counter);
}

void	load_img_3(t_mlx_data *data, int i, int j, int counter)
{
	if (data->map[j][i] == 'L')
	{
		if (counter % 70000 < 35000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->graphic.left_1_img, i * 32, j * 32);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->graphic.left_2_img, i * 32, j * 32);
	}
	else if (data->map[j][i] == 'U')
		if (counter % 70000 < 35000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->graphic.back_1_img, i * 32, j * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->graphic.back_2_img, i * 32, j * 32);
	else if (data->map[j][i] == 'E')
		if (counter % 70000 < 35000)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.exit_2_img, i * 32, j * 32);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->graphic.exit_1_img, i * 32, j * 32);
}
