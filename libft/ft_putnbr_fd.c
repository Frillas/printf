/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:42:17 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/15 11:31:35 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_size_str(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static size_t	ft_power(int size)
{
	int		i;
	size_t	res;

	i = 0;
	res = 1;
	while (i < size)
	{
		res = res * 10;
		i++;
	}
	return (res);
}

static void	ft_write_char(int n, int fd)
{
	size_t	size;
	size_t	power;
	size_t	i;
	char	c[1];

	i = 0;
	size = ft_size_str(n);
	power = ft_power(size - 1);
	while (i < size)
	{
		c[0] = (n / power) + 48;
		write(fd, c, 1);
		n = n % power;
		power = power / 10;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		ft_write_char(n, fd);
	if (n < 0 && n > -2147483648)
	{
		n = n * (-1);
		write(fd, "-", 1);
		ft_write_char(n, fd);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
}
