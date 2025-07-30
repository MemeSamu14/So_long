/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:32:02 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/28 11:22:50 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// IN BASE AL VALORE CHE HA REGULATOR SI STAMPA E FERMA
// PER OGNI SINGOLO ERRORE
// 1 = ERRORE SUI BORDI DELLA MAPPA
// 2 = ERRORE SULLA LUNGHEZZA DELLE LINEE DELLA MAPPA
// 3 = NUMERO MINIMO DI COLLEZIONABILI PALYER E USCITE
// 4 = NO PASSAGGI VALIDI
// 5 = CARATTERI NELLA MAPPA VALIDI

int	map_checks(t_mlx_data *data)
{
	map_truncate(data->map, data->matrix_len);
	if (map_lines_not_equal(data->map, data->matrix_len) == 2)
		return (ft_printf("Error\nThe map is not equally written"), 1);
	else if (map_border_valid(data->map, data->matrix_len) == 1)
		return (ft_printf("Error\nThe map is not close by walls"), 1);
	else if (coll_exit_p1_checker(data->map, data->matrix_len) == 3)
		return (1);
	else if (path_check(data) == 4)
		return (ft_printf("Error\nThere is not an available path"), 1);
	else if (valid_characters(data) == 5)
		return (ft_printf("Error\nThere is one invalid char in the map"), 1);
	return (0);
}

int	valid_characters(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < data->matrix_len)
	{
		i = 0;
		while (i < (int)ft_strlen(data->map[0]))
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0' && \
			data->map[j][i] != 'P' && data->map[j][i] != 'E' && \
			data->map[j][i] != 'C' && data->map[j][i] != 'M')
				return (5);
			i++;
		}
		j++;
	}
	return (0);
}

//riempie la matrice con la mappa del file map.bar
char	**fill_matrix(t_mlx_data *data, char **av)
{
	int	fd;
	int	matrix_len;

	matrix_len = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->map[matrix_len] = get_next_line_bonus(fd);
	while (data->map[matrix_len])
	{
		matrix_len++;
		data->map[matrix_len] = get_next_line_bonus(fd);
	}
	close(fd);
	if (ft_strlen(data->map[0]) < 3)
	{
		free_matrix(data->map, matrix_len);
		return (ft_printf("Error\nThe map is too small on the X axis"), NULL);
	}
	if (ft_strlen(data->map[0]) < 4 && matrix_len < 4)
	{
		free_matrix(data->map, matrix_len);
		return (ft_printf("Error\nThe map is too small on both axis"), NULL);
	}
	return (data->map);
}

// conta linee della mappa per allocare la matrice
char	**map_allocation(int *len, char **av)
{
	int			fd;
	t_mlx_data	data;
	char		*line;

	data.matrix_len = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nAn error occurred with the file"), NULL);
	line = get_next_line_bonus(fd);
	if (!line)
		return (close(fd), NULL);
	while (line)
	{
		data.matrix_len++;
		free(line);
		line = get_next_line_bonus(fd);
	}
	free(line);
	close(fd);
	if (data.matrix_len < 3)
		return (ft_printf("Error\nThe map is too small on the Y axis"), NULL);
	if (map_malloc(&data, av) == NULL)
		return (0);
	*len = data.matrix_len;
	return (data.map);
}

void	*map_malloc(t_mlx_data *data, char **av)
{
	data->map = ft_calloc(sizeof(char *), data->matrix_len + 1);
	if (!data->map)
		return (NULL);
	data->map = fill_matrix(data, av);
	if (data->map == NULL)
		return (NULL);
	return (data);
}
