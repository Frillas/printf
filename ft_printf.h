/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:29:15 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/24 16:28:08 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_char(va_list args);
int		ft_ptrchar(va_list args);
int		ft_adr(va_list args);
int		ft_int(va_list args);
int		ft_unsigned(va_list args);
int		ft_lowhex(va_list args);
int		ft_upperhex(va_list args);
size_t	ft_size(size_t n);
void	ft_puthex(unsigned long int n, int low);
void	ft_unsigned_nbr(unsigned int nbr);

#endif
