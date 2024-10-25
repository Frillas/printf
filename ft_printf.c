/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:30:26 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/25 12:03:30 by aroullea         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tot;

	i = 0;
	tot = 0;
	va_start(args, str);
	while (str[i])
	{
		count = 0;
		if (str[i] == '%' && str[i + 1] == 'c')
			count = ft_char(args);
		else if (str[i] == '%' && str[i + 1] == 's')
			count = ft_ptrchar(args);
		else if (str[i] == '%' && str[i + 1] == 'p')
			count = ft_adr(args);
		else if (str[i] == '%' && ((str[i + 1] == 'd') || (str[i + 1] == 'i')))
			count = ft_int(args);
		else if (str[i] == '%' && str[i + 1] == 'u')
			count = ft_unsigned(args) + 1;
		else if (str[i] == '%' && str[i + 1] == 'x')
			count = ft_lowhex(args) + 1;
		else if (str[i] == '%' && str[i + 1] == 'X')
			count = ft_upperhex(args) + 1;
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			i++;
			tot++;
		}
		else if (str[i - 1] == '%')
			;
		else
			write(1, &str[i], sizeof(char));
		tot = count + tot;
		i++;
	}
	va_end(args);
	return (tot);
}

int	main(void)
{
	unsigned int nb = 456789;
	unsigned int nb1 = 987653;
	int res;
	char *ptr = NULL;
	res = ft_printf("%u %u %%%%%%%%%%%%%%%%",nb, nb1);
	printf("%d\n",res);
	
	res = printf("%u %u %%%%%%%%%%%%%%%%", nb, nb1);
	printf("%d\n",res);
	printf("\n");
	printf("%p %s", NULL , ptr);
}
