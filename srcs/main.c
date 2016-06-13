/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:37:41 by lgatibel          #+#    #+#             */
/*   Updated: 2016/06/03 11:36:42 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libol.h>

int				main(int ac, char **av)
{
	t_window	win;

	if (ac == 2)
	{
		ft_verif_args(av[1], &win);
		if (win.ft_reset == NULL)
			ft_help();
		ft_create_picture(av[1], WIDTH, HEIGHT, &win);
	}
	else
		ft_help();
	return (0);
}
