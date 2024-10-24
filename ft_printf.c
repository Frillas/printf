/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:30:26 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/24 16:32:09 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tot;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			count = ft_char(args);
		else if (str[i] == '%' && str[i + 1] == 's')
			count = ft_ptrchar(args);
		else if (str[i] == '%' && str[i + 1] == 'p')
			count = ft_adr(args);
		else if (str[i] == '%' && ((str[i + 1] == 'd') || (str[i + 1] == 'i')))
			count = ft_int(args);
		else if (str[i] == '%' && str[i + 1] == 'u')
			count = ft_unsigned(args);
		else if (str[i] == '%' && str [i + 1] == 'x')
			count = ft_lowhex(args);
		else if (str[i] == '%' && str[i + 1] == 'X')
			count = ft_upperhex(args);
		else if (str[i] == '%' && str[i + 1] == '%')
			write(1, "%", 1);
		else if (str[i - 1] == '%')
			;
		else
			write(1, &str[i], sizeof(char));
		tot = count + tot;
		i++;
	}
	va_end (args);
	return (i + tot);
}

int	main(void)
{
	int nombre = 10;
	ft_printf("%d %p\n",10, &nombre);
}
