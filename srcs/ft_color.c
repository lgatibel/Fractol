/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:38:04 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 10:35:03 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

void				ft_color(t_window *win, t_fractol_point *point)
{
	int		color;

	if (point->iter > 0)
		color = win->color / point->iter;
	else
		color = win->color / 1;
	ft_memcpy((&win->line[((int)point->x * 4) +
				((int)point->y * win->size_line)]), &color, 4);
}
