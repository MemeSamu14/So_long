/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:20:35 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/21 12:36:24 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rng(int j)
{
	int	random_number;

	srand(time(NULL));
	random_number = rand() % 100 + 1;
	random_number = random_number + j;
	return (random_number);
}

int	rng_background(int j, int i)
{
	int	random_number;

	srand(time(NULL));
	random_number = rand() % 100 + 1;
	random_number = random_number + (j * i + 1);
	if (random_number % 2 == 0)
		return ('2');
	else
		return ('0');
}

void	random_if(t_mlx_data *data, int i, int j, int random)
{
	if (data->map[j][i] == '0')
		data->map[j][i] = rng_background(j, i);
	else if (data->map[j][i] == 'C')
	{
		data->coins++;
		if (random % 10 == 0)
			data->map[j][i] = '7';
		else if (random % 3 == 0)
			data->map[j][i] = '8';
		else
			data->map[j][i] = '9';
	}
}

void	random_matrix(t_mlx_data *data)
{
	int	i;
	int	j;
	int	random;

	i = 0;
	j = 0;
	random = 0;
	while (j < data->matrix_len)
	{
		i = 0;
		while (i < (int)ft_strlen(data->map[0]))
		{
			random = rng(j);
			random_if(data, i, j, random);
			i++;
		}
		j++;
	}
}
