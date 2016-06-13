/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:16:09 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 10:41:04 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

int				ft_change_color(int keycode, t_window *win)
{
	if (keycode == 35)
		win->color = 0xFF0000;
	else if (keycode == 15)
		win->color = 0x66FF00;
	return (win->color);
}

/*
** 15 = couleu custom
** 35 = Reset color
*/

void			ft_move(int keycode, t_window *window)
{
	if (keycode == 123)
		window->x1 -= MOVE;
	else if (keycode == 124)
		window->x1 += MOVE;
	else if (keycode == 125)
		window->y1 += MOVE;
	else if (keycode == 126)
		window->y1 -= MOVE;
}

/*
** 123 = left;
** 124 = right;
** 125 = down;
** 126 = up;
*/

static int		ft_lock(t_window *win)
{
	if (win->lock == 1)
		return (0);
	else if (win->lock == 0)
		return (1);
	return (win->lock);
}

int				ft_change(int keycode, t_window *window)
{
	t_window	*win;

	win = window;
	win->color = ft_change_color(keycode, win);
	if (keycode == 53)
		ft_exit(keycode);
	else if (keycode == 51)
		win->ft_reset(win);
	else if (keycode > 122 && keycode < 127)
		ft_move(keycode, win);
	else if (keycode == 49)
		win->lock = ft_lock(win);
	win->ft_color(win);
	ft_refresh(win);
	if (win->ft_color == ft_color_julia_thread)
		ft_print_lock(win);
	return (0);
}
