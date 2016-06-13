/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:27:52 by lgatibel          #+#    #+#             */
/*   Updated: 2015/12/11 12:27:37 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(char *str)
{
	int		i;
	char	*charac;

	i = 0;
	charac = "\n\t\v\r\f";
	while (charac[i])
	{
		if (charac[i] == *str)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_calc(char *str, int i)
{
	int n;

	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - 48;
		i++;
	}
	return (n);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] && !ft_isalpha((char)str[i]) && ft_isprint(str[i])) ||
			ft_sign((char *)(str + i)))
	{
		if (str[i] == '-')
			sign = -1;
		if ((str[i] == '-' && !ft_isdigit(str[i + 1])) ||
				(str[i] == '+' && !ft_isdigit(str[i + 1])))
			return (0);
		else if (ft_isdigit(str[i]))
			return (sign * ft_calc((char *)str, i));
		i++;
	}
	return (0);
}
