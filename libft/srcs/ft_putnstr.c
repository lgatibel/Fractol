/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:07:29 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/17 15:32:23 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, int n)
{
	int i;

	i = 0;
	if (s)
		while (s[i] && i < n)
		{
			ft_putchar(s[i]);
			i++;
		}
}
