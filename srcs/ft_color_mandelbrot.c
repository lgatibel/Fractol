/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:04:55 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/01 16:03:30 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

static void				*ft_color_picture_thread_1(void *args)
{
	t_window		*win;
	t_fractol_point	point;

	win = args;
	point.x = -1;
	point.y = -1;
	while (++point.x <= win->x / 2)
	{
		while (++point.y < win->y / 2)
		{
			point.cr = 1.5f * (point.x - (win->x / 2)) /
				(win->x * win->zoom * 0.5) + win->x1;
			point.ci = ((point.y - (win->y / 2)) / (win->y * win->zoom * 0.5)) +
				win->y1;
			point.iter = ft_iteration_mandelbrot(&point, win);
			if (point.iter > MANDELBROT_ITER)
				ft_color(win, &point);
		}
		point.y = -1;
	}
	pthread_exit(NULL);
}

static void				*ft_color_picture_thread_2(void *args)
{
	t_window		*win;
	t_fractol_point	point;

	win = args;
	point.x = win->x / 2;
	point.y = -1;
	while (++point.x < win->x)
	{
		while (++point.y < win->y / 2)
		{
			point.cr = 1.5f * (point.x - (win->x / 2)) /
				(win->x * win->zoom * 0.5) + win->x1;
			point.ci = ((point.y - (win->y / 2)) /
					(win->y * win->zoom * 0.5)) + win->y1;
			point.iter = ft_iteration_mandelbrot(&point, win);
			if (point.iter > MANDELBROT_ITER)
				ft_color(win, &point);
		}
		point.y = -1;
	}
	pthread_exit(NULL);
}

static void				*ft_color_picture_thread_3(void *args)
{
	t_window		*win;
	t_fractol_point	point;

	win = args;
	point.x = win->x / 2;
	point.y = win->y / 2 - 1;
	while (++point.x < win->x)
	{
		while (++point.y < win->y)
		{
			point.cr = 1.5f * (point.x - (win->x / 2)) /
				(win->x * win->zoom * 0.5) + win->x1;
			point.ci = ((point.y - (win->y / 2)) / (win->y * win->zoom * 0.5)) +
				win->y1;
			point.iter = ft_iteration_mandelbrot(&point, win);
			if (point.iter > MANDELBROT_ITER)
				ft_color(win, &point);
		}
		point.y = win->y / 2 - 1;
	}
	pthread_exit(NULL);
}

static void				*ft_color_picture_thread_4(void *args)
{
	t_window		*win;
	t_fractol_point	point;

	win = args;
	point.x = -1;
	point.y = win->y / 2 - 1;
	while (++point.x <= win->x - 1)
	{
		while (++point.y < win->y)
		{
			point.cr = 1.5f * (point.x - (win->x / 2)) /
				(win->x * win->zoom * 0.5) + win->x1;
			point.ci = ((point.y - (win->y / 2)) / (win->y * win->zoom * 0.5)) +
				win->y1;
			point.iter = ft_iteration_mandelbrot(&point, win);
			if (point.iter > MANDELBROT_ITER)
				ft_color(win, &point);
		}
		point.y = win->y / 2 - 1;
	}
	pthread_exit(NULL);
}

void					ft_color_mandelbrot_thread(t_window *win)
{
	pthread_t thread_1;
	pthread_t thread_2;
	pthread_t thread_3;
	pthread_t thread_4;

	win->line = mlx_get_data_addr(win->img, &win->bpp, &win->size_line,
			&win->endian);
	ft_clear_picture(win);
	pthread_create(&thread_1, NULL, ft_color_picture_thread_1, win);
	pthread_join(thread_1, NULL);
	pthread_create(&thread_2, NULL, ft_color_picture_thread_2, win);
	pthread_create(&thread_3, NULL, ft_color_picture_thread_3, win);
	pthread_create(&thread_4, NULL, ft_color_picture_thread_4, win);
	pthread_join(thread_2, NULL);
	pthread_join(thread_3, NULL);
	pthread_join(thread_4, NULL);
	ft_refresh(win);
}
