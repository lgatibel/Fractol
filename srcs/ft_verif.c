/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:49:35 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:18:09 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

static void		ft_set_julia(t_window *win)
{
	win->ft_reset = ft_reset_julia;
	win->ft_color = ft_color_julia_thread;
}

static void		ft_set_mandelbrot(t_window *win)
{
	win->ft_reset = ft_reset_mandelbrot;
	win->ft_color = ft_color_mandelbrot_thread;
}

static void		ft_set_fractol(t_window *win)
{
	win->ft_reset = ft_reset_fractol;
	win->ft_color = ft_color_fractol_thread;
}

void			ft_verif_args(char *av, t_window *win)
{
	int		cpt;
	char	*fractal[4];

	fractal[0] = "Julia";
	fractal[1] = "Mandelbrot";
	fractal[2] = "Fractol";
	fractal[3] = "Help";
	cpt = -1;
	win->ft_reset = NULL;
	win->ft_color = NULL;
	while (++cpt < 4)
	{
		if (!ft_strcmp(fractal[cpt], av))
			break ;
	}
	if (cpt > 3)
		return ;
	else if (cpt == 0)
		ft_set_julia(win);
	else if (cpt == 1)
		ft_set_mandelbrot(win);
	else if (cpt == 2)
		ft_set_fractol(win);
	else if (cpt == 3)
		ft_show_controls();
}
