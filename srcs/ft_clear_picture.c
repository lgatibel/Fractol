/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_picture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:25:47 by lgatibel          #+#    #+#             */
/*   Updated: 2016/05/23 10:53:33 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

void		ft_clear_picture(t_window *win)
{
	int		position;
	int		octet;
	int		color;

	color = 0;
	octet = win->bpp / 8;
	position = 0;
	while (position < (win->size_line * win->y))
	{
		ft_memcpy(win->line + position, &color, octet);
		position += octet;
	}
}
