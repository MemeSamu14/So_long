/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:15:57 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:41 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//effettua una duplicazione della matrice
char	**strdup_marix(char **map, int matrix_len)
{
	int		i;
	int		j;
	char	**matrix_dup;

	j = 0;
	matrix_dup = ft_calloc(sizeof(char *), matrix_len + 1);
	while (j < matrix_len)
	{
		i = 0;
		while (map[j][i])
			i++;
		matrix_dup[j] = ft_calloc(sizeof(char *), i);
		i = 0;
		while (map[j][i])
		{
			matrix_dup[j][i] = map[j][i];
			i++;
		}
		j++;
	}
	return (matrix_dup);
}

//libera la memoria allocata da una matrice
void	free_matrix(char **matrix, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
}

//stammpa una matrice
void	print_matrix(char **matrix, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("Matrix :\n");
	while (j < len)
	{
		i = 0;
		while (matrix[j][i])
		{
			ft_printf("%c ", matrix[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

// funzione che elimina tutti i dati del collegamento
void	free_all(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_matrix(data->map, data->matrix_len);
	exit(1);
}

// mette le immagini sulla finestra
void	img_from_sprites_init(t_mlx_data *data)
{
	img_paths(data);
	paths_to_img(data);
}
