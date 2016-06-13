/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_picture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:15:59 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:30:33 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

static void		ft_calc_zoom(int x, int y, t_window *win)
{
	double		diffx;
	double		diffy;
	double		diffx1;
	double		diffy1;

	diffx = ((win->x - x) / win->x / win->zoom);
	diffy = x / win->x / win->zoom;
	diffx1 = (win->y - y) / win->y / win->zoom;
	diffy1 = y / win->y / win->zoom;
	if (diffx != diffy && diffx1 != diffy1)
	{
		win->x1 += diffy - diffx;
		win->y1 += diffy1 - diffx1;
		while (win->iter_max < 200)
			win->iter_max += 5;
	}
}

static int		ft_mouse(int button, int x, int y, t_window *win)
{
	double		zoom;

	zoom = 0;
	if (x < 1 || x > win->x || y < 1 || y > win->y)
		return (0);
	if (button == 4 || button == 2)
		zoom = -1;
	else if (button == 5 || button == 1)
		zoom = 1;
	if (zoom != 0)
	{
		if (zoom < 0 && win->zoom > ZOOM)
			win->zoom /= 1.150;
		else if (zoom > 0)
			win->zoom *= 1.150;
		if (win->zoom > ZOOM)
			ft_calc_zoom(x, y, win);
		win->ft_color(win);
		ft_print_info(win, x, y);
	}
	return (0);
}

void			ft_create_picture(char *av, int x, int y,
		t_window *win)
{
	win->x = x;
	win->y = y;
	win->ft_reset(win);
	win->mlx = mlx_init();
	win->img = mlx_new_image(win->mlx, win->x, win->y);
	win->win = mlx_new_window(win->mlx, win->x, win->y, av);
	win->ft_color(win);
	mlx_key_hook(win->win, ft_change, win);
	if (win->ft_color != ft_color_julia_thread)
		mlx_mouse_hook(win->win, ft_mouse, win);
	else
		mlx_hook(win->win, 6, (1L << 0), ft_mouse_hook_julia, win);
	mlx_mouse_hook(win->win, ft_mouse, win);
	mlx_loop(win->mlx);
}
