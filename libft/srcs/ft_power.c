/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:40:10 by lgatibel          #+#    #+#             */
/*   Updated: 2016/02/11 15:08:24 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int pow)
{
	int		i;
	int		tmp;

	i = 1;
	tmp = nb;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		nb *= tmp;
		i++;
	}
	return (nb);
}
