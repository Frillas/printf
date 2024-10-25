/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:10:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/25 11:38:50 by aroullea         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

int	ft_lowhex(va_list args)
{
	unsigned long int	res;
	int	count;

	count = 0;
	res = va_arg(args, unsigned long int);
	count = ft_puthex(res, 1);
	return (count);
}

int	ft_upperhex(va_list args)
{
	unsigned long int	res;
	int	count;

	count = 0;
	res = va_arg(args, unsigned long int);
	count = ft_puthex(res, 0);
	return (count);
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

int	ft_puthex(unsigned long int n, int low)
{
	char	c;
	int		res;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, low);
	res = n % 16;
	if ((res > 9) && low)
		c = res + 87;
	else if ((res > 9) && !low)
		c = res + 55;
	else
		c = res + 48;
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_unsigned_nbr(unsigned int nbr)
{
	char	c;
	int		res;
	int		count;

	count = 0;
	if (nbr >= 10)
		count += ft_unsigned_nbr(nbr / 10);
	res = nbr % 10;
	c = res + 48;
	write(1, &c, 1);
	count++;
	return (count);
}
