/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:29:15 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/25 14:49:13 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_check_tot(const char *str, size_t *j, int tot);
int		ft_check(const char *str, int i);
int		ft_check_count(va_list args, const char *str, size_t i);
int		ft_char(va_list args);
int		ft_ptrchar(va_list args);
int		ft_adr(va_list args);
int		ft_int(va_list args);
int		ft_unsigned(va_list args);
int		ft_lowhex(va_list args);
int		ft_upperhex(va_list args);
size_t	ft_size(int n);
int		ft_puthex(unsigned long int n, int low);
int		ft_unsigned_nbr(unsigned int nbr);

#endif
