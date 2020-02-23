/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:28:52 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/09 06:45:05 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		len;
	int		del;
	int		i;

	len = 0;
	del = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			del += 1;
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
		{
			len += 1;
			del = 0;
		}
		if (del > 1)
		{
			ft_putendl("ERROR");
			exit(0);
		}
	}
	return (len);
}

static char	**ft_allocate_str(char **tab, char *str, char del)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != del)
		{
			count++;
			if (str[i + 1] == '\0' || str[i + 1] == del)
			{
				if (!(*tab = ft_strnew(count)))
					return (NULL);
				tab++;
				count = 0;
			}
		}
	}
	return (tab);
}

static char	**ft_fill_array(char **array, char const *str, char del)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != del)
		{
			array[k][j] = str[i];
			j++;
			if ((str[i + 1] == '\0' || str[i + 1] == del))
			{
				array[k][j] = '\0';
				k++;
				j = 0;
			}
		}
		i++;
	}
	array[k] = 0;
	return (array);
}

char		**ft_split_format(char *str, char c)
{
	char	**wordsarray;
	int		i;

	if (!str)
		return (NULL);
	i = count_words(str, c);
	if (!(wordsarray = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	ft_allocate_str(wordsarray, str, c);
	ft_fill_array(wordsarray, str, c);
	return (wordsarray);
}
