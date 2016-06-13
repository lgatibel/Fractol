/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook_julia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:15:37 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/01 13:06:55 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

int				ft_mouse_hook_julia(int x, int y, t_window *win)
{
	if (win->lock == 1)
		return (0);
	if (x < win->x && x > -1 && y < win->y && y > -1)
	{
		if (x > win->x / 2)
			win->cr = JULIA_CR + x * 0.0012;
		else
			win->cr = JULIA_CR - x * 0.0012;
		if (y > win->y / 2)
			win->ci = JULIA_CI + y * 0.0012;
		else
			win->ci = JULIA_CI - y * 0.0012;
		ft_color_julia_thread(win);
		ft_print_info(win, x, y);
	}
	return (0);
}
