/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:59:27 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:38 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// trova le coordinate del player
void	find_my_p(char **map_dup, int *x, int *y, int matrix_len)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 1;
	check = 0;
	while (j < matrix_len)
	{
		i = 0;
		while (map_dup[j][i])
		{
			if (map_dup[j][i] == 'P')
			{
				check = 1;
				break ;
			}
			i++;
		}
		if (check == 1)
			break ;
		j++;
	}
	*x = i;
	*y = j;
}

void	find_my_e(char **map_dup, int *x, int *y, int matrix_len)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 1;
	check = 0;
	while (j < matrix_len)
	{
		i = 0;
		while (map_dup[j][i])
		{
			if (map_dup[j][i] == 'E')
			{
				check = 1;
				break ;
			}
			i++;
		}
		if (check == 1)
			break ;
		j++;
	}
	*x = i;
	*y = j;
}

//modifica la matrice affinche' questa sia riempita di x 
//(tutto per controllare il valid path)
void	flood_fill(char **matrix, int x, int y)
{
	if (matrix[y][x] == 'x' || matrix[y][x] == '1' || matrix[y][x] == 'M')
		return ;
	matrix[y][x] = 'x';
	flood_fill(matrix, (x + 1), y);
	flood_fill(matrix, (x - 1), y);
	flood_fill(matrix, x, (y + 1));
	flood_fill(matrix, x, (y - 1));
}

int	path_check(t_mlx_data *data)
{
	int		i;
	int		j;
	char	**dup;

	j = 1;
	dup = strdup_marix(data->map, data->matrix_len);
	find_my_p(dup, &data->x_player, &data->y_player, data->matrix_len);
	find_my_e(dup, &data->x_exit, &data->y_exit, data->matrix_len);
	flood_fill(dup, data->x_player, data->y_player);
	while (j < data->matrix_len)
	{
		i = 0;
		while (dup[j][i])
		{
			if (dup[j][i] == 'E' || dup[j][i] == 'C')
				return (free_matrix(dup, data->matrix_len), 4);
			i++;
		}
		j++;
	}
	free_matrix(dup, data->matrix_len);
	return (0);
}
