/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:46:13 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:29:44 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

void			ft_print_lock(t_window *win)
{
	if (win->ft_color != ft_color_julia_thread)
		return ;
	if (win->lock == 1)
		mlx_string_put(win->mlx, win->win, 715, 8, 0x000000, "lock on");
	else if (win->lock == 0)
		mlx_string_put(win->mlx, win->win, 715, 8, 0x000000, "lock off");
}

void			ft_print_info(t_window *win, int x, int y)
{
	char	*coordonates;
	char	*tmp;
	int		infox;
	int		infoy;

	infox = 650;
	infoy = 767;
	while (++infox < 795)
	{
		while (++infoy < 795)
			mlx_pixel_put(win->mlx, win->win, infox, infoy, 0xFFFFFF);
		infoy = 767;
	}
	win->tmp = ft_itoa(x);
	coordonates = ft_strjoin("x:", win->tmp);
	tmp = ft_strjoin(coordonates, ", y:");
	ft_strdel(&coordonates);
	ft_strdel(&win->tmp);
	win->tmp = ft_itoa(y);
	coordonates = ft_strjoin(tmp, win->tmp);
	mlx_string_put(win->mlx, win->win, 660, 770, 0x000000, coordonates);
	ft_print_lock(win);
	ft_strdel(&win->tmp);
	free(tmp);
	free(coordonates);
}
