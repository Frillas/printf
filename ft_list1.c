/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:45:41 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/24 16:17:22 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_char(va_list args)
{
	char	c;
	int		count;

	c = (char) va_arg(args, int);
	write(1, &c, sizeof(char));
	count = 1;
	return (count);
}

int	ft_ptrchar(va_list args)
{
	char	*dst;

	dst = va_arg(args, char *);
	ft_putstr_fd(dst, 1);
	return (ft_strlen(dst));
}

int	ft_adr(va_list args)
{
	unsigned long int	res;

	res = va_arg(args, unsigned long int);
	write(1, "0x", 2);
	ft_puthex(res, 1);
	return (ft_size(res));
}

int	ft_int(va_list args)
{
	int	res;

	res = va_arg(args, int);
	ft_putnbr_fd(res, 1);
	return (ft_size(res));
}

int	ft_unsigned(va_list args)
{
	unsigned int	res;

	res = va_arg(args, unsigned int);
	ft_unsigned_nbr(res);
	return (ft_size(res));
}
