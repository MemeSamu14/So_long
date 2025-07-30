/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:46:36 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:34 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//muove il player sulla destra
void	movement_right(t_mlx_data *data)
{
	if (movement_right_2(data) == 1)
		return ;
	else if (data->map[data->y_player][data->x_player + 1] == '1')
	{
		data->map[data->y_player][data->x_player] = 'R';
		return ;
	}
	else if (data->map[data->y_player][data->x_player + 1] == '7' || \
		data->map[data->y_player][data->x_player + 1] == '9' || \
		data->map[data->y_player][data->x_player + 1] == '8')
		data->coin_taken++;
	data->map[data->y_player][data->x_player] = '0';
	data->map[data->y_exit][data->x_exit] = 'E';
	data->map[data->y_player][data->x_player + 1] = 'R';
	data->x_player += 1;
	data->moves++;
	ft_printf("\nMoves ---> %d\n", data->moves);
}

void	movement_left(t_mlx_data *data)
{
	if (movement_left_2(data) == 1)
		return ;
	else if (data->map[data->y_player][data->x_player - 1] == '1')
	{
		data->map[data->y_player][data->x_player] = 'L';
		return ;
	}
	else if (data->map[data->y_player][data->x_player - 1] == '7' || \
		data->map[data->y_player][data->x_player - 1] == '8' || \
		data->map[data->y_player][data->x_player - 1] == '9')
		data->coin_taken++;
	data->map[data->y_player][data->x_player] = '0';
	data->map[data->y_exit][data->x_exit] = 'E';
	data->map[data->y_player][data->x_player - 1] = 'L';
	data->x_player -= 1;
	data->moves++;
	ft_printf("\nMoves ---> %d\n", data->moves);
}

void	movement_up(t_mlx_data *data)
{
	if (movement_up_2(data) == 1)
		return ;
	else if (data->map[data->y_player - 1][data->x_player] == '1')
	{
		data->map[data->y_player][data->x_player] = 'U';
		return ;
	}
	else if (data->map[data->y_player - 1][data->x_player] == '7' || \
		data->map[data->y_player - 1][data->x_player] == '8' || \
		data->map[data->y_player - 1][data->x_player] == '9')
		data->coin_taken++;
	data->map[data->y_player][data->x_player] = '0';
	data->map[data->y_exit][data->x_exit] = 'E';
	data->map[data->y_player - 1][data->x_player] = 'U';
	data->y_player -= 1;
	data->moves++;
	ft_printf("\nMoves ---> %d\n", data->moves);
}

void	movement_down(t_mlx_data *data)
{
	if (movement_down_2(data) == 1)
		return ;
	else if (data->map[data->y_player + 1][data->x_player] == '1')
	{
		data->map[data->y_player][data->x_player] = 'P';
		return ;
	}
	else if (data->map[data->y_player + 1][data->x_player] == '7' || \
		data->map[data->y_player + 1][data->x_player] == '8' || \
		data->map[data->y_player + 1][data->x_player] == '9')
		data->coin_taken++;
	data->map[data->y_player][data->x_player] = '0';
	data->map[data->y_exit][data->x_exit] = 'E';
	data->map[data->y_player + 1][data->x_player] = 'P';
	data->y_player += 1;
	data->moves++;
	ft_printf("\nMoves ---> %d\n", data->moves);
}
