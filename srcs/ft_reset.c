/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:34:56 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:19:30 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

void			ft_reset_julia(t_window *window)
{
	window->x1 = 0;
	window->y1 = 0;
	window->lock = 0;
	window->zoom = ZOOM;
	window->iter_max = JULIA_ITER;
	window->cr = JULIASTART;
	window->ci = JULIASTART;
	window->color = START_COLOR;
}

void			ft_reset_mandelbrot(t_window *window)
{
	window->x1 = -0.6;
	window->y1 = 0;
	window->lock = 0;
	window->zoom = ZOOM;
	window->iter_max = MANDELBROT_ITER;
	window->cr = MANDELBROT_CR;
	window->ci = MANDELBROT_CI;
	window->color = START_COLOR;
}

void			ft_reset_fractol(t_window *window)
{
	window->x1 = 0;
	window->y1 = 0;
	window->lock = 0;
	window->zoom = ZOOM;
	window->iter_max = FRACTOL_ITER;
	window->cr = FRACTOL_CR;
	window->ci = FRACTOL_CI;
	window->color = START_COLOR;
}
