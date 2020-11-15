/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:55:20 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/30 19:19:28 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strspn(const char *str, const char *charset)
{
	int i;
	int j;
	int k;
	int m;

	k = 0;
	m = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j] && (k += 1))
				break ;
			else
				k = 0;
		if (k == 0)
			break ;
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j] && (m += 1))
				break ;
	}
	return (m);
}
