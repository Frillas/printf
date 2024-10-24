/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/19 15:13:26 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_countwords(char const *s, char c, int i, int count)
{
	int	find;

	find = 0;
	if (s[0] == '\0' && c == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (find == 0))
		{
			find = 1;
			count++;
			i++;
		}
		else if ((s[i] == c) && (find == 1))
		{
			find = 0;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_count_char(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static void	ft_add_char(char *dest, char const *s, char c, int *i)
{
	int	j;

	j = 0;
	while (s[*i] && s[*i] != c)
	{
		dest[j] = s[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
}

static char	**ft_sort(char const *s, char c, int words, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < words)
	{
		while (s[i] == c)
			i++;
		j = ft_count_char(s, c, i);
		str[k] = (char *) ft_calloc((j + 1), (sizeof(char)));
		if (str[k] == NULL)
		{
			while (k >= 0)
				free (str[k--]);
			free (str);
			return (NULL);
		}
		ft_add_char(str[k], s, c, &i);
		k++;
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c, 0, 0);
	str = (char **) ft_calloc ((words + 1), (sizeof(char *)));
	if (str == NULL)
		return (0);
	str = ft_sort(s, c, words, str);
	return (str);
}
