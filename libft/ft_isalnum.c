/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:13:36 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/11 06:52:39 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	int	test1;
	int	test2;
	int	test3;

	test1 = (c >= 48 && c <= 57);
	test2 = (c >= 65 && c <= 90);
	test3 = (c >= 97 && c <= 122);
	if (test1 || test2 || test3)
		return (8);
	else
		return (0);
}