/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:18:11 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:31 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_right_2(t_mlx_data *data)
{
	if (data->x_player + 1 == data->x_exit && data->y_player == data->y_exit)
	{
		if (data->coins == data->coin_taken)
		{
			data->moves++;
			ft_printf("\nMoves ---> %d\n", data->moves);
			free_display(data);
			free_all(data);
		}
		data->map[data->y_player][data->x_player] = '0';
		data->map[data->y_player][data->x_player + 1] = 'R';
		data->x_player += 1;
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		return (1);
	}
	else if (data->map[data->y_player][data->x_player + 1] == 'M')
	{
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		free_display(data);
		free_all(data);
	}
	return (0);
}

int	movement_left_2(t_mlx_data *data)
{
	if (data->x_player - 1 == data->x_exit && data->y_player == data->y_exit)
	{
		if (data->coins == data->coin_taken)
		{
			data->moves++;
			ft_printf("\nMoves ---> %d\n", data->moves);
			free_display(data);
			free_all(data);
		}
		data->map[data->y_player][data->x_player] = '0';
		data->map[data->y_player][data->x_player - 1] = 'L';
		data->x_player -= 1;
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		return (1);
	}
	else if (data->map[data->y_player][data->x_player - 1] == 'M')
	{
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		free_display(data);
		free_all(data);
		return (1);
	}
	return (0);
}

int	movement_up_2(t_mlx_data *data)
{
	if (data->x_player == data->x_exit && data->y_player - 1 == data->y_exit)
	{
		if (data->coins == data->coin_taken)
		{
			data->moves++;
			ft_printf("\nMoves ---> %d\n", data->moves);
			free_display(data);
			free_all(data);
		}
		data->map[data->y_player][data->x_player] = '0';
		data->map[data->y_player - 1][data->x_player] = 'U';
		data->y_player -= 1;
		data->moves++;
		return (1);
	}
	else if (data->map[data->y_player - 1][data->x_player] == 'M')
	{
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		ft_printf("\nMcazzi");
		free_display(data);
		free_all(data);
	}
	return (0);
}

int	movement_down_2(t_mlx_data *data)
{
	if (data->x_player == data->x_exit && data->y_player + 1 == data->y_exit)
	{
		if (data->coins == data->coin_taken)
		{
			data->moves++;
			ft_printf("\nMoves ---> %d\n", data->moves);
			free_display(data);
			free_all(data);
		}
		data->map[data->y_player][data->x_player] = '0';
		data->map[data->y_player + 1][data->x_player] = 'P';
		data->y_player += 1;
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		return (1);
	}
	else if (data->map[data->y_player + 1][data->x_player] == 'M')
	{
		data->moves++;
		ft_printf("\nMoves ---> %d\n", data->moves);
		free_display(data);
		free_all(data);
	}
	return (0);
}
