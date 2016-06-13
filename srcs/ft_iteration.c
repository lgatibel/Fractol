/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:56:04 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/01 14:45:37 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

int				ft_iteration_julia(t_fractol_point *point, t_window *win)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zr = 1.5 * (point->x - (win->x / 2)) / (0.5 * win->zoom * win->x) + win->x1;
	zi = 1.5 * (point->y - (win->y / 2)) / (0.5 * win->zoom * win->y) + win->y1;
	i = 255;
	while (((zr * zr) + (zi * zi)) < 4 && i > win->iter_max)
	{
		tmp = zr;
		zr = ((zr * zr) - (zi * zi)) + win->cr;
		zi = (2 * zi * tmp) + win->ci;
		--i;
	}
	return (i);
}

int				ft_iteration_fractol(t_fractol_point *point, t_window *win)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zr = 1.5 * (point->x - (win->x / 2)) / (0.5 * win->zoom * win->x) + win->x1;
	zi = 1.5 * (point->y - (win->y / 2)) / (0.5 * win->zoom * win->y) + win->y1;
	i = 255;
	while (((zr * zr) + (zi * zi)) < 4 && i > win->iter_max)
	{
		tmp = zr;
		zr = ((zr * zr) - (zi * zi)) + FRACTOL_CR;
		zi = (2 * zi * tmp) + FRACTOL_CI;
		--i;
	}
	return (i);
}

int				ft_iteration_mandelbrot(t_fractol_point *point, t_window *win)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zi = 0;
	zr = 0;
	i = 255;
	while (((zr * zr) + (zi * zi)) < 4 && i > win->iter_max)
	{
		tmp = zr;
		zr = ((zr * zr) - (zi * zi)) + point->cr;
		zi = (2 * zi * tmp) + point->ci;
		--i;
	}
	return (i);
}
