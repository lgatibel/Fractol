/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:34:42 by lgatibel          #+#    #+#             */
/*   Updated: 2016/04/26 12:13:22 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

int				ft_refresh(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}
