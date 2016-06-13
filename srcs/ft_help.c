/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:50:56 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:27:21 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

void			ft_help(void)
{
	ft_putendl("Wrong argument: Use [Julia, Mandelbrot, Fractol, Help]");
	exit(2);
}

void			ft_show_controls(void)
{
	ft_putendl("Controls: [skroll whell], [click], [p], [r], [arrow keys], "
			"[space bar],\n [del], [mouse move], [right click], [left click]");
	exit(2);
}
