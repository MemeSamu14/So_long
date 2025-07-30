/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:30:08 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/27 19:06:23 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		free_display(data);
		free_all(data);
	}
	else if (keysym == 100 || keysym == 65363)
		movement_right(data);
	else if (keysym == 97 || keysym == 65361)
		movement_left(data);
	else if (keysym == 119 || keysym == 65362)
		movement_up(data);
	else if (keysym == 115 || keysym == 65364)
		movement_down(data);
	return (0);
}

int	handle_mouse_input(t_mlx_data *data)
{
	free_display(data);
	free_all(data);
	return (0);
}
