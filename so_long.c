/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:02:26 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/28 15:02:09 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	funct_ptr(void *arg)
{
	t_mlx_data	*data;
	char		*n_moves;
	int			i;
	int			j;

	data = (t_mlx_data *)arg;
	i = 0;
	j = 0;
	n_moves = NULL;
	n_moves = ft_itoa(data->moves);
	load_map(data, i, j);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 8, 14, 0xFFFFFF, n_moves);
	free(n_moves);
	n_moves = NULL;
	n_moves = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 8, 14, 0xFFFFFF, n_moves);
	free(n_moves);
	return (0);
}

int	so_long(t_mlx_data data, char **av)
{
	data.map = map_allocation(&data.matrix_len, av);
	if (!data.map)
		return (ft_printf("Error\nmap is buttata difori"), 1);
	if (map_checks(&data) == 1)
		return (free_matrix(data.map, data.matrix_len), 1);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (int)ft_strlen(data.map[0]) \
				* 32, data.matrix_len * 32, "YuGiOh");
	if (data.win_ptr == NULL)
		return (free_all(&data), 1);
	img_paths(&data);
	paths_to_img(&data);
	random_matrix(&data);
	mlx_hook(data.win_ptr, 02, 1L << 0, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 1L << 3, handle_mouse_input, &data);
	mlx_loop_hook(data.mlx_ptr, funct_ptr, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		data.coins = 0;
		data.moves = 0;
		data.coin_taken = 0;
		return (so_long(data, av), 0);
	}
	ft_printf("Please insert the name of a map file");
	return (0);
}
