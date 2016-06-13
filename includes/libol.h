/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libol.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 11:04:57 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:31:36 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOL_H
# define LIBOL_H
# define WIDTH 800
# define HEIGHT 800
# define MOVE (.05 / (0.6 - window->x1))
# define START_COLOR 0x66FF00
# define JULIA_ITER 90
# define JULIA_CR -.77691311542185
# define JULIA_CI .12428146607278
# define JULIASTART 0
# define MANDELBROT_ITER 90
# define MANDELBROT_CR -.7
# define MANDELBROT_CI .27015
# define ZOOM 1
# define FRACTOL_ITER 90
# define FRACTOL_CR .285
# define FRACTOL_CI .01

# include <libft.h>
# include <mlx.h>
# include <pthread.h>

typedef struct		s_fractol_point
{
	double		x;
	double		y;
	double		cr;
	double		ci;
	double		iter;
}					t_fractol_point;

typedef struct		s_window
{
	void	*mlx;
	void	*img;
	void	*win;
	double	x;
	double	y;
	double	x1;
	double	y1;
	double	zoom;
	double	iter_max;
	double	cr;
	double	ci;
	int		size_line;
	int		endian;
	int		bpp;
	int		lock;
	int		color;
	char	*line;
	char	*tmp;
	void	(*ft_reset)(struct s_window *);
	void	(*ft_color)(struct s_window *);
}					t_window;

void				ft_help(void);
void				ft_show_controls(void);
void				ft_verif_args(char *av, t_window *win);

int					ft_exit(int keycode);
int					ft_change(int keycode, t_window *win);

void				ft_create_picture(char *av, int x, int y,
					t_window *win);

void				ft_reset_julia(t_window *window);
void				ft_color_julia_thread(t_window *win);
int					ft_iteration_julia(t_fractol_point *point, t_window *win);
int					ft_mouse_hook_julia(int x, int y, t_window *win);

void				ft_reset_mandelbrot(t_window *window);
void				ft_color_mandelbrot_thread(t_window *win);
int					ft_iteration_mandelbrot(t_fractol_point *point,
		t_window *win);

void				ft_reset_fractol(t_window *window);
void				ft_color_fractol_thread(t_window *win);
int					ft_iteration_fractol(t_fractol_point *point, t_window *win);

int					ft_refresh(t_window *win);
void				ft_clear_picture(t_window *win);
void				ft_color(t_window *win, t_fractol_point *point);
void				ft_print_info(t_window *win, int x, int y);
void				ft_print_lock(t_window *win);
#endif
