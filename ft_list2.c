/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:10:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/24 16:20:26 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhex(va_list args)
{
	unsigned long int	res;

	res = va_arg(args, unsigned long int);
	ft_puthex(res, 1);
	return (ft_size(res));
}

int	ft_upperhex(va_list args)
{
	unsigned long int	res;

	res = va_arg(args, unsigned long int);
	ft_puthex(res, 0);
	return (ft_size(res));
}

size_t	ft_size(size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned long int n, int low)
{
	char	c;
	int		res;

	if (n >= 16)
		ft_puthex(n / 16, low);
	res = n % 16;
	if ((res > 9) && low)
		c = res + 87;
	else if ((res > 9) && !low)
		c = res + 55;
	else
		c = res + 48;
	write (1, &c, 1);
}

void	ft_unsigned_nbr(unsigned int nbr)
{
	char	c;
	int		res;

	if (nbr >= 10)
		ft_unsigned_nbr(nbr / 10);
	res = nbr % 10;
	c = res + 48;
	write(1, &c, 1);
}
